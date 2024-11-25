#include "PublicationHandler.h"

template <typename T>
void PublicationHandler<T>::displayPublications(const std::vector<T>& publications) {
    for (const auto& publication : publications) {
        publication.display();
    }
}