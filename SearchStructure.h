//
// Created by Bay Foley-Cox on 5/23/22.
//

#ifndef WEAKLY_QUEUEISH_STRUCTURES_SEARCHSTRUCTURE_H
#define WEAKLY_QUEUEISH_STRUCTURES_SEARCHSTRUCTURE_H

#include <vector>

template <class Query, class Data>
class SearchStructure {
    virtual Data* query(Query q) = 0;
    SearchStructure(std::vector<Data>) = 0;
};

class dict : SearchStructure<int, std::string> {
    
};



#endif //WEAKLY_QUEUEISH_STRUCTURES_SEARCHSTRUCTURE_H
