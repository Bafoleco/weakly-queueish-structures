//
// Created by Bay Foley-Cox on 6/2/22.
//

#ifndef WEAKLY_QUEUEISH_STRUCTURES_VECDICT_H
#define WEAKLY_QUEUEISH_STRUCTURES_VECDICT_H

#include "vector"
#include "optional"
#include "algorithm"

template <class Key, class Value> class VecDict {

    typedef std::pair<Key, Value> KeyValuePair;

private:
    //sorted vector holding the elements
    std::vector<KeyValuePair> pairs;

public:
    std::optional<Value> query(Key key);
    VecDict();
    VecDict(std::vector<KeyValuePair> objects);
    VecDict(VecDict<Key, Value> &all, std::vector<int> indices);
};

template<class Key, class Value>
std::optional<Value> VecDict<Key, Value>::query(Key key) {

    auto comp = [](KeyValuePair x, Key y){ return x.first < y; };

    auto pair = std::lower_bound(pairs.begin(), pairs.end(), key, comp);
    return (*pair).second;
}

template<class Key, class Value>
VecDict<Key, Value>::VecDict(std::vector<KeyValuePair> objects) : pairs(objects) {

}

template<class Key, class Value>
VecDict<Key, Value>::VecDict(VecDict<Key, Value> &all, std::vector<int> indices) {
    //we need to sort indices (can do efficiently with radix sort)
    std::sort(indices.begin(), indices.end());

    //then construct by pulling elements from all objects
    for (int i : indices) {
        pairs.push_back(all.pairs[i]);
    }
}

template<class Key, class Value>
VecDict<Key, Value>::VecDict() {

};



#endif //WEAKLY_QUEUEISH_STRUCTURES_VECDICT_H
