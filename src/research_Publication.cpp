#include "research_Publication.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
#include <set>

// Define the display function
void Publication::display() const {
    std::cout << "Title: " << (title_.empty() ? "N/A" : title_) << "\n"
               << "Venue: " << (venue_.empty() ? "N/A" : venue_) << "\n"
               << "Authors: ";
    if (authors_.empty()) {
        std::cout << "N/A";
    } else {
        for (size_t i = 0; i < authors_.size(); ++i) {
            std::cout << authors_[i].name << " (" << authors_[i].affiliation << ")";
            if (i < authors_.size() - 1) {
                std::cout << ", ";
            }
        }
    }
    std::cout << "\nYear: " << (year_.empty() ? "N/A" : year_) << "\n"
               << "DOI: " << (doi_.empty() ? "N/A" : doi_) << "\n\n";
}

// Define the constructor
Publication::Publication(const std::string& title, const std::string& venue, const std::vector<Author>& authors, const std::string& year, const std::string& doi)
    : title_(title), venue_(venue), authors_(authors), year_(year), doi_(doi) {}

// Define the getAuthors function
const std::vector<Author>& Publication::getAuthors() const {
    return authors_;
}