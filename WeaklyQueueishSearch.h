//
// Created by Bay Foley-Cox on 5/23/22.
//

#ifndef WEAKLY_QUEUEISH_STRUCTURES_WEAKLYQUEUEISHSEARCH_H
#define WEAKLY_QUEUEISH_STRUCTURES_WEAKLYQUEUEISHSEARCH_H

#include <vector>
#include <queue>
#include <list>
#include "SearchStructure.h"

template <class Query, class Object> class WeaklyQueueishSearch {

    struct store {
        Object object;
        typename std::list<store>::iterator queue_ptr;
        int queue_index;
    };

    private:
        int num_elems;
        int k;
        //we use std::list (a doubly linked list) as our queue implementation
        std::vector<std::list<store>> queues;
        std::vector<SearchStructure<Query, store>> search_structures;
        void repair_queue(int queue_index);
        int min_size(int queue_index);
        int max_size(int queue_index);

public:
        Object* query(Query);

};


#endif //WEAKLY_QUEUEISH_STRUCTURES_WEAKLYQUEUEISHSEARCH_H
