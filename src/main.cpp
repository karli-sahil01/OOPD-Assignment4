#include "bibTeX_Parser.h"
#include "research_Publication.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <cassert>
#include <set>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Please provide at least one author name as an argument.\n";
        return 1;
    }

    std::vector<std::string> searchAuthors;
    for (int i = 1; i < argc; ++i) {
        searchAuthors.push_back(argv[i]);
    }

    std::string bibFilename = "data/publist.bib";
    std::string csvFilename = "data/affiliation.csv";

    std::vector<Author> faculty = read_csv(csvFilename);
    std::vector<Publication> publications = parseBibTexFile(bibFilename, faculty);

    std::map<std::string, std::vector<Publication>> authorPublications;

    for (const auto& publication : publications) {
        for (const auto& author : publication.getAuthors()) {  // Use the getter method
            for (const auto& searchAuthor : searchAuthors) {
                if (author.name.find(searchAuthor) != std::string::npos) {
                    authorPublications[searchAuthor].push_back(publication);
                }
            }
        }
    }

    for (const auto& searchAuthor : searchAuthors) {
        std::cout << "\nPublications for author: " << searchAuthor << "\n";
        if (authorPublications[searchAuthor].empty()) {
            std::cout << "No publications found for this author.\n";
            continue;
        }

        int totalCoAuthors = 0;
        for (const auto& publication : authorPublications[searchAuthor]) {
            publication.display();
            totalCoAuthors += publication.getAuthors().size() - 1;  // Use the getter method to access authors
        }

        double avgCoAuthors = static_cast<double>(totalCoAuthors) / authorPublications[searchAuthor].size();
        std::cout << "Average number of co-authors per paper: " << avgCoAuthors << "\n";
    }

    return 0;
}