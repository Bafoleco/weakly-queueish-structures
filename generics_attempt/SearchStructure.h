//
// Created by Bay Foley-Cox on 5/23/22.
//

#ifndef WEAKLY_QUEUEISH_STRUCTURES_SEARCHSTRUCTURE_H
#define WEAKLY_QUEUEISH_STRUCTURES_SEARCHSTRUCTURE_H

#include <vector>
#include <map>

template <class Query, class Data>
class SearchStructure {
    virtual Data query(Query q) = 0;
    virtual SearchStructure<Query, Data>* createStructure(std::vector<std::pair<Query, Data>>) = 0;
};


#endif //WEAKLY_QUEUEISH_STRUCTURES_SEARCHSTRUCTURE_H
