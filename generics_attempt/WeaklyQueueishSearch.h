//
// Created by Bay Foley-Cox on 5/23/22.
//

#ifndef WEAKLY_QUEUEISH_STRUCTURES_WEAKLYQUEUEISHSEARCH_H
#define WEAKLY_QUEUEISH_STRUCTURES_WEAKLYQUEUEISHSEARCH_H

#include <vector>
#include <queue>
#include <list>
#include <set>
#include <cmath>

#include "SearchStructure.h"

template <class Query, class Object, class Factory> class WeaklyQueueishSearch {

    //we need to store an iterator to the elements queue alongside the element itself
    struct store {
        Object object;
        typename std::list<Object>::iterator queue_ptr;
        int queue_index;

        store(Object object, typename std::list<Object>::iterator queue_ptr, int queue_index) {
            this->object = object;
            this->queue_index = queue_index;
            this->queue_ptr = queue_ptr;
        }
    };

    private:
        int num_elems;
        //max queue index log log num_elems
        int k;
        //we use std::list (a doubly linked list) as our queue implementation
        std::vector<std::list<Object>> queues;
        std::vector<SearchStructure<Query, store>*> search_structures;
        void repair_queue(int queue_index);
        int min_size(int queue_index);
        int max_size(int queue_index);

public:
    Object query(Query);
    WeaklyQueueishSearch(std::vector<Object>);
};

template <class Query, class Object, class Factory>
Object WeaklyQueueishSearch<Query, Object, Factory>::query(Query q) {
    for (int i = 0; i <= k; i++) {
        store* search_result = search_structures[i].query(q);
        if (search_result != NULL) {
            typename std::list<store>::iterator elem_iter = search_result->queue_ptr;
            Object* data = search_result->object;

            int queue_index = search_result->queue_index;
            std::list<store>& queue = queues[queue_index];

            //do the required transfer

            //repair the queue
            repair_queue(queue_index);

            return data;
        }
    }
    return NULL;
}

template<class Query, class Object, class Factory>
void WeaklyQueueishSearch<Query, Object, Factory>::repair_queue(int queue_index) {
    //check if index is in bounds
    if (queue_index >= k) {
        return;
    }

    //check if queue is too small
    std::list<store>& queue = queues[queue_index];
    if (queue.size() < min_size(queue_index)) {
        int to_steal = max_size(queue_index) - queue.size();
        //do the stealing

        //we may need to repair the queue we took values from
        repair_queue(queue_index + 1);
    }
}

template <class Query, class Object, class Factory>
int WeaklyQueueishSearch<Query, Object, Factory>::min_size(int queue_index) {
    //our indices are 1 less than Iacono's for use with vectors
    queue_index += 1;
    return std::pow(2, (std::pow(2, queue_index) - 1)) + 1;
}

template <class Query, class Object, class Factory>
int WeaklyQueueishSearch<Query, Object, Factory>::max_size(int queue_index) {
    if (queue_index == k) {
        //queue k has no max size
        return INT_MAX;
    }
    //our indices are 1 less than Iacono's for use with vectors
    queue_index += 1;
    return std::pow(2, std::pow(2, queue_index));
}

template <class Query, class Object, class Factory>
WeaklyQueueishSearch<Query, Object, Factory>::WeaklyQueueishSearch(std::vector<Object> objects) {
    num_elems = objects.size();
    k = std::floor(std::log(std::log(num_elems)));

    int vec_index = 0;
    for (int i = 0; i < k; i++) {
        while (queues[i].size() < max_size(i)) {
            queues[i].push_back(objects[vec_index].second);
            vec_index++;
        }
    }

    //generate the structures
    std::vector<store> elems;
    for (int i = 0; i < k; i++) {
        //collect the elements
        for (auto it = queues[i].begin(); it != queues[i].end(); it++) {
            Object obj = *it;
            store s(obj, it, i);
            elems.push_back(s);
        }

        //generate store


    }
}


#endif //WEAKLY_QUEUEISH_STRUCTURES_WEAKLYQUEUEISHSEARCH_H
