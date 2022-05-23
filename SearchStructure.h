//
// Created by Bay Foley-Cox on 5/23/22.
//

#ifndef WEAKLY_QUEUEISH_STRUCTURES_SEARCHSTRUCTURE_H
#define WEAKLY_QUEUEISH_STRUCTURES_SEARCHSTRUCTURE_H

#include <set>

template <class Query, class Data>
class SearchStructure {
    virtual Data* query(Query q) = 0;
    SearchStructure(std::set<Data>) = 0;
};

#endif //WEAKLY_QUEUEISH_STRUCTURES_SEARCHSTRUCTURE_H
