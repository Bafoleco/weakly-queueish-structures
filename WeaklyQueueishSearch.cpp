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

            //do the required transfer

            //repair the queue
            repair_queue(queue_index);

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
    if (queue.size() < min_size(queue_index)) {

        int to_steal = max_size(queue_index) - queue.size();

        //do the stealing


        //we may need to repair the queue we took values from
        repair_queue(queue_index + 1);
    }
}

template<class Query, class Object>
int WeaklyQueueishSearch<Query, Object>::min_size(int queue_index) {
    //our indices are 1 less than Iacono's for use with vectors
    queue_index += 1;
    return std::pow(2, (std::pow(2, queue_index) - 1)) + 1;
}

template<class Query, class Object>
int WeaklyQueueishSearch<Query, Object>::max_size(int queue_index) {
    //our indices are 1 less than Iacono's for use with vectors
    queue_index += 1;
    return std::pow(2, std::pow(2, queue_index));
}
