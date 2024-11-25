#ifndef PUBLICATIONBASE_H
#define PUBLICATIONBASE_H

class PublicationBase {
public:
    virtual void display() const = 0;
    virtual ~PublicationBase() = default;
};

#endif  // PUBLICATIONBASE_H