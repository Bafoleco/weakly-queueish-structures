//
// Created by Bay Foley-Cox on 5/23/22.
//

#include <complex>
#include "WeaklyQueueishSearch.h"

template <class Query, class Object>
Object* WeaklyQueueishSearch<Query, Object>::query(Query q) {
    for (int i = 0; i <= k; i++) {
        store* search_result = search_structures[i].query(q);
        if (search_result != NULL) {
            typename std::list<store>::iterator elem_iter = search_result->queue_ptr;
            Object* data = search_result->object;

            int queue_index = search_result->queue_index;
            std::list<store>& queue = queues[queue_index];


            return data;

        }
    }
    return NULL;
}

template<class Query, class Object>
void WeaklyQueueishSearch<Query, Object>::repair_queue(int queue_index) {
    //check if index is in bounds
    if (queue_index >= k) {
        return;
    }
    //check if queue is too small
    std::list<store>& queue = queues[queue_index];
    if (queue.size() < std::pow(2, (std::pow(2, (queue_index + 1)) - 1))) {

    }

}
