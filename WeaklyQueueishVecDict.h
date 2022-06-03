//
// Created by Bay Foley-Cox on 6/2/22.
//

#ifndef WEAKLY_QUEUEISH_STRUCTURES_WEAKLYQUEUEISHVECDICT_H
#define WEAKLY_QUEUEISH_STRUCTURES_WEAKLYQUEUEISHVECDICT_H

#include <list>
#include <cmath>
#include <iostream>
#include <iterator>
#include "VecDict.h"

template <class Key, class Value> class WeaklyQueueishVecDict {

    typedef std::pair<Key, Value> KeyValuePair;

    struct store {
        KeyValuePair keyValuePair;
        typename std::list<std::pair<int, int>>::iterator queue_ptr;
    };

private:
    int num_elems;
    //max queue index log log num_elems
    int k;
    //we use std::list (a doubly linked list) as our queue implementation
    //we store indexes into vector k
    std::vector<std::list<std::pair<int, int>>> queues;
    //we keep a sorted list of the key value pairs as our dictionary
    std::vector<VecDict<Key, store>> dicts;
    //collection of indices used in reconstruction
    std::vector<int> collectedIndices;
    void repair_queue(int queue_index);
    int min_size(int queue_index);
    int max_size(int queue_index);
public:
    void printQueue();
    std::optional<Value> query(Key);
    WeaklyQueueishVecDict(std::vector<KeyValuePair>);
};

template <class Key, class Value>
std::optional<Value> WeaklyQueueishVecDict<Key, Value>::query(Key q) {
    for (int i = 0; i < k; i++) {
        std::optional<store> search_result_opt = dicts[i].query(q);

//        printQueue();

//        std::cout << search_result_opt.has_value() << std::endl;
        if (search_result_opt.has_value()) {
            store search_result = search_result_opt.value();

            auto elem_iter = search_result.queue_ptr;
            KeyValuePair keyValuePair = search_result.keyValuePair;
            int queue_index = elem_iter->second;

//            std::cout << "queue index: " << queue_index << std::endl;


            //do the required transfer of the element
            queues.back().splice(queues.back().end(), queues[queue_index], elem_iter);
            //update the queue index of the element
            elem_iter->second = k - 1;

//            //repair the queue
//            std::cout << "queue index: " << queue_index << std::endl;
//            std::cout << "queue size: " << queues[queue_index].size() << std::endl;

            //find the queue where we must start repairing

            if (queues[queue_index].size() < min_size(queue_index)) {
                repair_queue(queue_index);
            }

            return keyValuePair.second;
        }
    }
    return {};
}

template <class Key, class Value>
void WeaklyQueueishVecDict<Key, Value>::repair_queue(int queue_index) {
    int curr_index = queue_index;
    //collect the elements from prior queues
    int maxDictSize = 0;
    int numCollected = 0;
    for (int i = 0; i < queue_index; i++) {
        for (auto it = queues[i].begin(); it != queues[i].end(); it++) {
            collectedIndices[numCollected] = it->first;
            numCollected++;
        }
        maxDictSize += max_size(i);
    }

    //we have already done first check if we call the function
    do {
//        std::cout << "stealing. start size: " << queues[curr_index].size() << std::endl;
        int to_steal = max_size(curr_index) - queues[curr_index].size();

        int stolen = 0;
        while (stolen < to_steal) {
            queues[curr_index].splice(queues[curr_index].end(), queues[curr_index + 1], queues[curr_index + 1].begin());
            queues[curr_index].back().second = curr_index;
            stolen++;
        }

        //collect the elements from this queue
        for (auto it = queues[curr_index].begin(); it != queues[curr_index].end(); it++) {
            collectedIndices[numCollected] = it->first;
            numCollected++;
        }

        maxDictSize += max_size(curr_index);
//        dicts[curr_index] = VecDict(dicts[k-1], collectedIndices, maxDictSize);
        dicts[curr_index].overwrite(dicts[k-1], collectedIndices, numCollected);

//        std::cout << "num collected: " << numCollected << std::endl;
        //we may need to repair the queue we took values from
        curr_index++;
    } while (queues[curr_index].size() < min_size(curr_index));
}

template <class Key, class Value>
int WeaklyQueueishVecDict<Key, Value>::min_size(int queue_index) {
    //our indices are 1 less than Iacono's for use with vectors
    queue_index++;
    return std::pow(2, (std::pow(2, queue_index) - 1)) + 1;
}

template <class Key, class Value>
int WeaklyQueueishVecDict<Key, Value>::max_size(int queue_index) {
    if (queue_index == k - 1) {
        //queue k has no max size
        return INT_MAX;
    }
    //our indices are 1 less than Iacono's for use with vectors
    queue_index++;
    return std::pow(2, std::pow(2, queue_index));
}

template <class Key, class Value>
WeaklyQueueishVecDict<Key, Value>::WeaklyQueueishVecDict(std::vector<KeyValuePair> objects) :
    num_elems(objects.size()), k(std::floor(log2(log2(num_elems)))), dicts(k) {

        int vec_index = 0;
        for (int i = 0; i < k; i++) {
            queues.emplace_back();
            while (queues[i].size() < max_size(i) && vec_index < objects.size()) {
                queues[i].push_back({vec_index, i});
                vec_index++;
            }
        }

        //collect all elements
        std::vector<std::pair<Key, store>> elems;
        for (int i = 0; i < k; i++) {
            //collect the elements
            for (auto it = queues[i].begin(); it != queues[i].end(); it++) {
                KeyValuePair obj = objects[it->first];
                store s = store {
                        obj,
                        it,
                };
                elems.push_back({obj.first, s});
            }
        }

        //create the top level dict
        dicts[k-1] = VecDict(elems, elems.size());

        //create lower level dicts from indices and top level dict
        std::vector<int> indicesToInclude;

        int maxSize = 0;
        for (int i = 0; i < k - 1; i++) {
            //collect the indices
            for (auto it = queues[i].begin(); it != queues[i].end(); it++) {
                indicesToInclude.push_back(it->first);
            }
            maxSize += max_size(i);
            dicts[i] = VecDict(dicts[k-1], indicesToInclude, maxSize);
        }
        std::cout << "max size: " << maxSize << std::endl;
        collectedIndices = std::vector<int>(maxSize);
}

template<class Key, class Value>
void WeaklyQueueishVecDict<Key, Value>::printQueue() {
        for (int i = 0; i < k; i++) {
            std::cout << "queue " << i << ": ";
            for (auto pair : queues[i]) {
                std::cout << "(" <<  pair.first << ", " << pair.second << "), ";
            }
            std::cout << " | ";
        }

        std::cout << "k: " << k << std::endl;
}

#endif //WEAKLY_QUEUEISH_STRUCTURES_WEAKLYQUEUEISHVECDICT_H
