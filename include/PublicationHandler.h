#ifndef PUBLICATIONHANDLER_H
#define PUBLICATIONHANDLER_H

#include <vector>
#include "Pub_Base.h"

template <typename T>
class PublicationHandler {
public:
    static void displayPublications(const std::vector<T>& publications);
};

#endif  // PUBLICATIONHANDLER_H