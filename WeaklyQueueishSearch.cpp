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
    if (queue_index == k) {
        //queue k has no max size
        return INT_MAX;
    }
    //our indices are 1 less than Iacono's for use with vectors
    queue_index += 1;
    return std::pow(2, std::pow(2, queue_index));
}

template<class Query, class Object>
WeaklyQueueishSearch<Query, Object>::WeaklyQueueishSearch(std::vector<Object> objects) {
    num_elems = objects.size();
    k = std::floor(std::log(std::log(num_elems)));

    int vec_index = 0;
    for (int i = 0; i < k; i++) {
        while (queues[i].size() < max_size(i)) {
            queues[i].push_back(objects[vec_index]);
            vec_index++;
        }
    }

    //generate the structures
    std::vector<store> elems;
    for (int i = 0; i < k; i++) {
        //collect the elements
        for (typename std::list<store>::iterator it = queues[i].begin(); it++; it != queues[i].end()) {
            elems.push_back(it->object, it, i);
        }
        search_structures[i] = new SearchStructure<Query, store>(elems);
    }
}
