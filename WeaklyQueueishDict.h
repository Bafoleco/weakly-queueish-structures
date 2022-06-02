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
        //we store indexes into vector k
        std::vector<std::list<KeyValuePair>> queues;
        //we keep a sorted list of the key value pairs as our dictionary
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
        if (search_result_opt.has_value()) {
            store search_result = search_result_opt.value();
            typename std::list<KeyValuePair>::iterator elem_iter = search_result.queue_ptr;
            KeyValuePair keyValuePair = search_result.keyValuePair;
            int queue_index = search_result.queue_index;

            //do the required transfer of the element
            queues[queue_index].erase(elem_iter);
            queues.back().push_front(keyValuePair);

            //repair the queue
            if (queues[queue_index].size() < min_size(queue_index)) {
                repair_queue(queue_index);
            }

            return keyValuePair.second;
        }
    }
    return {};
}

template <class Key, class Value>
void WeaklyQueueishDict<Key, Value>::repair_queue(int queue_index) {
    int curr_index = queue_index;
    std::vector<std::pair<Key, store>> elems;
    //collect the elements from prior queues
    for (int i = 0; i < queue_index; i++) {
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

    //we have already done first check if we call the function
    do {
        int to_steal = max_size(curr_index) - queues[curr_index].size();

        //take the needed elements from the back of the next queue to the front of the current queue
        auto first = std::next(queues[curr_index + 1].end(), -1 * to_steal);
        auto last = queues[curr_index + 1].end();
        queues[curr_index].splice(queues[curr_index].begin(), queues[curr_index + 1], first, last);

        //collect the elements from this queue
        for (auto it = queues[curr_index].begin(); it != queues[curr_index].end(); it++) {
            KeyValuePair obj = *it;
            store s = store{
                    obj,
                    it,
                    curr_index,
            };
            elems.emplace_back(obj.first, s);
        }

        dicts[curr_index] = Dict(elems);

        //we may need to repair the queue we took values from
        curr_index++;
    } while (queues[curr_index].size() < min_size(curr_index));
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

    int vec_index = 0;
    for (int i = 0; i < k; i++) {
        queues.emplace_back();
        while (queues[i].size() < max_size(i) && vec_index < objects.size()) {
            queues[i].push_back(objects[vec_index]);
            vec_index++;
        }
    }

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

        //generate the structures
        dicts.emplace_back(elems);
    }
}
#endif //WEAKLY_QUEUEISH_STRUCTURES_WEAKLYQUEUEISHDICT_H
