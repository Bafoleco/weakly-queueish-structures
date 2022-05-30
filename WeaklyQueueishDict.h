//
// Created by Bay Foley-Cox on 5/29/22.
//

#ifndef WEAKLY_QUEUEISH_STRUCTURES_WEAKLYQUEUEISHDICT_H
#define WEAKLY_QUEUEISH_STRUCTURES_WEAKLYQUEUEISHDICT_H

#include <list>
#include <cmath>
#include <iostream>
#include <iterator>
#include "Dict.h"

template <class Key, class Value> class WeaklyQueueishDict {

    typedef std::pair<Key, Value> KeyValuePair;

    struct store {
        KeyValuePair keyValuePair;
        typename std::list<KeyValuePair>::iterator queue_ptr;
        int queue_index;
    };

    private:
        int num_elems;
        //max queue index log log num_elems
        int k;
        //we use std::list (a doubly linked list) as our queue implementation
        std::vector<std::list<std::pair<Key, Value>>> queues;
        std::vector<Dict<Key, store>> dicts;
        void repair_queue(int queue_index);
        int min_size(int queue_index);
        int max_size(int queue_index);
    public:
        std::optional<Value> query(Key);
        WeaklyQueueishDict(std::vector<KeyValuePair>);
};

template <class Key, class Value>
std::optional<Value> WeaklyQueueishDict<Key, Value>::query(Key q) {
    for (int i = 0; i < k; i++) {
        std::optional<store> search_result_opt = dicts[i].query(q);
//        std::cout << "searching queue " << i << std::endl;

        if (search_result_opt.has_value()) {
//            std::cout << "found value in queue " << i << std::endl;

            store search_result = search_result_opt.value();
            typename std::list<KeyValuePair>::iterator elem_iter = search_result.queue_ptr;
            KeyValuePair keyValuePair = search_result.keyValuePair;
            int queue_index = search_result.queue_index;

            //do the required transfer
            queues[queue_index].erase(elem_iter);
            queues.back().push_front(keyValuePair);

            //repair the queue
            repair_queue(queue_index);

            return keyValuePair.second;
        }
    }

    std::cout << "not found" << std::endl;
    return {};
}

template <class Key, class Value>
void WeaklyQueueishDict<Key, Value>::repair_queue(int queue_index) {
//    std::cout << "queue repair " << queue_index << std::endl;

    //check if queue is too small
    int curr_index = queue_index;
    while (queues[curr_index].size() < min_size(curr_index)) {
        int to_steal = max_size(curr_index) - queues[curr_index].size();

        //take the from the back of the next queue to the front of the current queue
        auto first = std::next(queues[curr_index + 1].end(), -1 * to_steal);
        auto last = queues[curr_index + 1].end();
        queues[curr_index].splice(queues[curr_index].begin(), queues[curr_index + 1], first, last);


        //TODO wasteful in that we don't transfer collection to next queue to repair
        //repair the associated data structure
        //collect the elements
        std::vector<std::pair<Key, store>> elems;
        for (int i = 0; i <= queue_index; i++) {
            for (auto it = queues[i].begin(); it != queues[i].end(); it++) {
                KeyValuePair obj = *it;
                store s = store{
                        obj,
                        it,
                        i,
                };
                elems.emplace_back(obj.first, s);
            }
        }

        dicts[curr_index] = Dict(elems);

        //we may need to repair the queue we took values from
        curr_index++;
    }
}

template <class Key, class Value>
int WeaklyQueueishDict<Key, Value>::min_size(int queue_index) {
    //our indices are 1 less than Iacono's for use with vectors
    queue_index++;
    return std::pow(2, (std::pow(2, queue_index) - 1)) + 1;
}

template <class Key, class Value>
int WeaklyQueueishDict<Key, Value>::max_size(int queue_index) {
    if (queue_index == k - 1) {
        //queue k has no max size
        return INT_MAX;
    }
    //our indices are 1 less than Iacono's for use with vectors
    queue_index++;
    return std::pow(2, std::pow(2, queue_index));
}

template <class Key, class Value>
WeaklyQueueishDict<Key, Value>::WeaklyQueueishDict(std::vector<KeyValuePair> objects) {
    num_elems = objects.size();
    k = std::floor(log2(log2(num_elems)));

    std::cout << "k:" << k << std::endl;

    int vec_index = 0;
    for (int i = 0; i < k; i++) {
        queues.emplace_back();
        while (queues[i].size() < max_size(i) && vec_index < objects.size()) {
            queues[i].push_back(objects[vec_index]);
            vec_index++;
        }
    }

    std::cout << "filled the queues" << std::endl;

    //generate the structures
    std::vector<std::pair<Key, store>> elems;
    for (int i = 0; i < k; i++) {
        //collect the elements
        for (auto it = queues[i].begin(); it != queues[i].end(); it++) {
            KeyValuePair obj = *it;
            store s = store {
                obj,
                it,
                i,
            };
            elems.push_back({obj.first, s});
        }

        std::cout << "create dict of size: " << elems.size() << std::endl;

        //generate the structures
        dicts.emplace_back(elems);
    }
}
#endif //WEAKLY_QUEUEISH_STRUCTURES_WEAKLYQUEUEISHDICT_H
