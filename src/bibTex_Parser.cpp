#include <string>
#include <vector>
#include "bibTeX_Parser.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <cassert>
#include <set>
#include <iostream>

using namespace std;
// Function to trim leading and trailing whitespace from a string
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

// Function to split a string by a given substring
vector<string> split(const string& str, const string& delimiter) {
    vector<string> tokens;
    size_t start = 0;
    size_t end = 0;

    while ((end = str.find(delimiter, start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
    }

    tokens.push_back(str.substr(start));
    return tokens;
}

std::vector<Author> read_csv(const std::string& filename) {
    std::vector<Author> faculty;
    std::ifstream file(filename);
    std::string line;

    // Skip the header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::vector<std::string> parts = split(line, ",");
        if (parts.size() == 2) {
            faculty.emplace_back(trim(parts[0]), trim(parts[1]));
        }
    }
    file.close();
    return faculty;
}

std::vector<Publication> parseBibTexFile(const std::string& filename, const std::vector<Author>& faculty) {
    std::ifstream file(filename);
    assert(file.is_open() && "Error: Could not open BibTeX file.");

    std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    std::vector<Publication> publications;
    std::istringstream stream(fileContent);
    std::string line, entryText;
    bool inEntry = false;

    while (std::getline(stream, line)) {
        if (line.find("@") != std::string::npos) {
            if (inEntry) {
                publications.push_back(parseBibTexEntry(entryText, faculty));
                entryText.clear();
            }
            inEntry = true;
        }
        if (inEntry) {
            entryText += line + "\n";
        }
    }

    if (inEntry) {
        publications.push_back(parseBibTexEntry(entryText, faculty));
    }

    return publications;
}

Publication parseBibTexEntry(const std::string& entryText, const std::vector<Author>& faculty) {
    // Validate braces
    assert(validateBraces(entryText) && "Invalid BibTeX entry: Mismatched braces");

    // Validate commas
    assert(validateCommas(entryText) && "Invalid BibTeX entry: Missing commas between fields");

    std::string title, venue, year, doi;
    std::vector<Author> authors;
    std::set<std::string> uniqueAuthors;  // To check for duplicate authors
    bool hasIIITDelhiAuthor = false;
    std::istringstream stream(entryText);
    std::string line;

    while (std::getline(stream, line)) {
        if (line.find("title") != std::string::npos) {
            title = trim(line.substr(line.find('{') + 1, line.find('}') - line.find('{') - 1));
        } else if (line.find("venue") != std::string::npos || line.find("journal") != std::string::npos) {
            venue = trim(line.substr(line.find('{') + 1, line.find('}') - line.find('{') - 1));
        } else if (line.find("author") != std::string::npos) {
            std::string authors_text = trim(line.substr(line.find('{') + 1, line.find('}') - line.find('{') - 1));
            std::vector<std::string> author_names = split(authors_text, "and");
            for (const auto& author_name : author_names) {
                auto name_parts = split(trim(author_name), ",");
                if (name_parts.size() == 2) {
                    std::string formatted_name = name_parts[1] + " " + name_parts[0];

                    // Check for duplicate authors
                    assert(uniqueAuthors.find(formatted_name) == uniqueAuthors.end() &&
                           "Invalid BibTeX entry: Duplicate author found");
                    uniqueAuthors.insert(formatted_name);

                    std::string affiliation = "Unknown";
                    for (const auto& faculty_author : faculty) {
                        if (formatted_name == " " + faculty_author.name) {
                            affiliation = faculty_author.affiliation;
                            if (isIIITDelhiAuthor(affiliation)) {
                                hasIIITDelhiAuthor = true;
                            }
                            break;
                        }
                    }
                    authors.emplace_back(formatted_name, affiliation);
                }
            }
        } else if (line.find("year") != std::string::npos) {
            year = trim(line.substr(line.find('{') + 1, line.find('}') - line.find('{') - 1));
        } else if (line.find("doi") != std::string::npos) {
            doi = trim(line.substr(line.find('{') + 1, line.find('}') - line.find('{') - 1));
        }
    }

    // Validate that at least one author belongs to IIIT-Delhi
        // Validate that at least one author belongs to IIIT-Delhi
    assert(hasIIITDelhiAuthor && "Invalid BibTeX entry: No author from IIIT-Delhi found");

    return Publication(title, venue, authors, year, doi);
}

bool validateBraces(const std::string& entryText) {
    int braceCount = 0;
    for (char c : entryText) {
        if (c == '{') braceCount++;
        else if (c == '}') braceCount--;
        if (braceCount < 0) return false;  // Closing brace before opening brace
    }
    return braceCount == 0;  // All braces should be matched
}

bool validateCommas(const std::string& entryText) {
    std::istringstream stream(entryText);
    std::string line;
    while (std::getline(stream, line)) {
        if (line.find('=') != std::string::npos) {
            // Check if the line ends with a comma or closing brace
            line = trim(line);
            if (!line.empty() && line.back() != ',' && line.back() != '}') {
                size_t nextLine = entryText.find(line) + line.length();
                if (nextLine < entryText.length() && entryText.find('}', nextLine) != nextLine) {
                    return false;  // Missing comma between fields
                }
            }
        }
    }
    return true;
}

bool isIIITDelhiAuthor(const std::string& affiliation) {
    // Convert affiliation to lowercase for case-insensitive comparison
    std::string lowerAffiliation = affiliation;
    std::transform(lowerAffiliation.begin(), lowerAffiliation.end(), lowerAffiliation.begin(), ::tolower);
    return lowerAffiliation.find("iiit-delhi") != std::string::npos ||
           lowerAffiliation.find("iiit delhi") != std::string::npos ||
           lowerAffiliation.find("indraprastha institute of information technology delhi") != std::string::npos ||
           lowerAffiliation.find("indraprastha institute of information technology, delhi") != std::string::npos;
}