//
// Created by Bay Foley-Cox on 5/29/22.
//

#ifndef WEAKLY_QUEUEISH_STRUCTURES_DICT_H
#define WEAKLY_QUEUEISH_STRUCTURES_DICT_H

#include <vector>
#include <map>

template <class Key, class Value> class Dict {
private:
    std::map<Key, Value> dict;

public:
    std::optional<Value> query(Key key);
    Dict<Key, Value>(std::vector<std::pair<Key, Value>>);
};

template<class Key, class Value>
std::optional<Value> Dict<Key, Value>::query(Key key) {
    if (dict.count(key) != 0) {
        dict[key];
    }
    if (dict.count(key) != 0) {
        return dict[key];
    }
    return {};
}

template<class Key, class Value>
Dict<Key, Value>::Dict(std::vector<std::pair<Key, Value>> pairs) : dict(pairs.begin(), pairs.end()) {
//    for (auto it : pairs) {
//        dict[it.first] = it.second;
//    }
}

#endif //WEAKLY_QUEUEISH_STRUCTURES_DICT_H
