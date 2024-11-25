// #ifndef BIBTEXPARSER_H
// #define BIBTEXPARSER_H

// #include <string>
// #include <vector>
// #include "Author.h"
// #include "Publication.h"

// std::vector<Author> read_csv(const std::string& filename);

// std::vector<Publication> parseBibTexFile(const std::string& filename, const std::vector<Author>& faculty);

// Publication parseBibTexEntry(const std::string& entryText, const std::vector<Author>& faculty);

// bool validateBraces(const std::string& entryText);

// bool validateCommas(const std::string& entryText);

// bool isIIITDelhiAuthor(const std::string& affiliation);

// #endif  // BIBTEXPARSER_H



#ifndef BIBTEXPARSER_H
#define BIBTEXPARSER_H

#include <string>
#include <vector>
#include "res_Author.h"
#include "research_Publication.h"

std::vector<Author> read_csv(const std::string& filename);

std::vector<Publication> parseBibTexFile(const std::string& filename, const std::vector<Author>& faculty);

Publication parseBibTexEntry(const std::string& entryText, const std::vector<Author>& faculty);

bool validateBraces(const std::string& entryText);

bool validateCommas(const std::string& entryText);

bool isIIITDelhiAuthor(const std::string& affiliation);

// Function to trim leading and trailing whitespace from a string
std::string trim(const std::string& str);

// Function to split a string by a given substring
std::vector<std::string> split(const std::string& str, const std::string& delimiter);

#endif  // BIBTEXPARSER_H