#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <string>
#include <vector>
#include "res_Author.h"
#include "Pub_Base.h"

class Publication : public PublicationBase {
private:
    std::string title_;
    std::string venue_;
    std::vector<Author> authors_;
    std::string year_;
    std::string doi_;

public:
    Publication(const std::string& title, const std::string& venue, const std::vector<Author>& authors, const std::string& year, const std::string& doi = "");

    void display() const override;

    const std::vector<Author>& getAuthors() const;
};

#endif  // PUBLICATION_H