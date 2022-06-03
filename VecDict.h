//
// Created by Bay Foley-Cox on 6/2/22.
//

#ifndef WEAKLY_QUEUEISH_STRUCTURES_VECDICT_H
#define WEAKLY_QUEUEISH_STRUCTURES_VECDICT_H

#include "vector"
#include "optional"
#include "algorithm"
#include <iostream>

template <class Key, class Value> class VecDict {

    typedef std::pair<Key, Value> KeyValuePair;

private:
    //sorted vector holding the elements
    std::vector<KeyValuePair> pairs;
    int num_elems;

public:
    std::optional<Value> query(Key key);
    VecDict();
    VecDict(std::vector<KeyValuePair> objects, int size);
    VecDict(VecDict<Key, Value> &all, std::vector<int> &indices, int size);
    void overwrite(VecDict<Key, Value> &all, std::vector<int> &indices, int toCopy);
};

template<class Key, class Value>
std::optional<Value> VecDict<Key, Value>::query(Key key) {

//    std::cout << "searching for: " << key << std::endl;
//    std::cout << "we store: " << pairs.size() << " elems" << std::endl;

//    for (KeyValuePair pair : pairs) {
//        std::cout << pair.first << std::endl;
//    }

    auto comp = [](KeyValuePair x, Key y){ return x.first < y; };
    auto pair = std::lower_bound(pairs.begin(), pairs.begin() + num_elems, key, comp);
    if (pair == pairs.end() || (*pair).first != key) {
//        std::cout << "could not find " << key << std::endl;
        return std::nullopt;
    }
//    std::cout << "pair found: (" << (*pair).first << ", " << (*pair).first << ") " << std::endl;

    return (*pair).second;
}

template<class Key, class Value>
VecDict<Key, Value>::VecDict(std::vector<KeyValuePair> objects, int size) : pairs(size), num_elems(objects.size()) {
    for (int i = 0; i < objects.size(); i++) {
        pairs[i] = objects[i];
    }
}

template<class Key, class Value>
VecDict<Key, Value>::VecDict(VecDict<Key, Value> &all, std::vector<int> &indices, int size) : pairs(size) {
    num_elems = indices.size();
    //we need to sort indices (can do efficiently with radix sort)
    std::sort(indices.begin(), indices.end());

    //then construct by pulling elements from all objects
    for (int i = 0; i < indices.size(); i++) {
        pairs[i] = all.pairs[indices[i]];
    }
}

template<class Key, class Value>
VecDict<Key, Value>::VecDict() {

}

template<class Key, class Value>
void VecDict<Key, Value>::overwrite(VecDict<Key, Value> &all,  std::vector<int> &indices, int toCopy) {
    num_elems = toCopy;
    //we need to sort indices (can do efficiently with radix sort)
    std::sort(indices.begin(), indices.begin() + toCopy);
    for (int i = 0; i < toCopy; i++) {
        pairs[i] = all.pairs[indices[i]];
    }
};



#endif //WEAKLY_QUEUEISH_STRUCTURES_VECDICT_H
