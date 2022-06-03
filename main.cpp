#include <iostream>
#include <chrono>
#include "Dict.h"
#include "WeaklyQueueishDict.h"
#include "WeaklyQueueishVecDict.h"
#include <set>

template <class Key, class Value> int timeWeaklyQueueishVecDictIdeal(int numIters, std::vector<std::pair<Key, Value>> pairs, std::vector<int> queries) {
    WeaklyQueueishVecDict<Key, Value> weaklyQueueishVecDict(pairs);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i : queries) {
        weaklyQueueishVecDict.query(i).value();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(end - start);
    return duration.count();
}

template <class Key, class Value> int timeVecDictIdeal(int numIters, std::vector<std::pair<Key, Value>> pairs, std::vector<int> queries) {
    VecDict<Key, Value> vecDict(pairs, pairs.size());
    auto start = std::chrono::high_resolution_clock::now();
    for (int i : queries) {
        vecDict.query(i).value();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(end - start);
    return duration.count();
}

//compares a VecDict with a WeaklyQueueishVecDict
void compareVecDictWQVecDict(int val, int k) {
    int maxValue = val;
    int numIters = 5;

    std::vector<std::pair<int, std::string>> pairs;
    for (int i = 0; i < maxValue; i++) {
        pairs.emplace_back(i, std::to_string(i) + "s");
    }

    std::vector<int> queries;
    std::set<int> noQuery;
    srand(time(nullptr));

    for (int j = 0; j < k; j++) {
        noQuery.insert(rand() % maxValue);
    }
    while (queries.size () < numIters * maxValue) {
        for (int i = 0; i < numIters; i++) {
            for (int j = 0; j < maxValue; j++) {
                if (queries.size() >= numIters * maxValue)
                    break;
                if (!noQuery.contains(j))
                    queries.push_back(j);
            }
        }
    }

    int weaklyQueueishTime = timeWeaklyQueueishVecDictIdeal(numIters, pairs, queries);
    int regularTime = timeVecDictIdeal(numIters, pairs, queries);

    // std::cout << "weakly queueish time: " << weaklyQueueishTime << std::endl;
    // std::cout << "regular time: " << regularTime << std::endl;
    // std::cout << "ratio: " << (double) weaklyQueueishTime/ regularTime << std::endl;
    std::cout << weaklyQueueishTime << ", " << regularTime ;
}

int testWeaklyQueueishVecDict() {
    int maxValue = 1024 * 1024;

    std::vector<std::pair<int, std::string>> associations;
    for (int i = 0; i < maxValue; i++) {
        associations.emplace_back(i, std::to_string(i) + "s");
    }

    WeaklyQueueishVecDict<int, std::string> weaklyQueueishVecDict(associations);

    int iters = 4;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iters; i++) {
        for (int j = 0; j < maxValue; j++) {
            weaklyQueueishVecDict.query(j);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto queueish_duration = duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Time taken by weakly queueish structure: "
              << queueish_duration.count() << " microseconds" << std::endl;

    //for comparison
    std::vector<std::pair<int, std::string>> associations2;
    for (int i = 0; i < maxValue; i++) {
        associations2.emplace_back(i, std::to_string(i) + "s");
    }
    Dict<int, std::string> dict(associations2);

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iters; i++) {
        for (int j = 0; j < maxValue; j++) {
            dict.query(j);
        }
    }
    end = std::chrono::high_resolution_clock::now();
    auto reg_duration = duration_cast<std::chrono::microseconds>(end - start);

    // std::cout << "Time taken by regular structure: "
    //           << reg_duration.count() << " microseconds" << std::endl;
    

    //std::cout << "ratio: " << (double) queueish_duration.count() / reg_duration.count() << std::endl;

    return 0;
}

int main() {

    std::cout << "Queueish value, weakly queueish, normal" << std::endl;
    int maxValue = 1024 * 10;
    for (int i = 0; i < maxValue; i+=100){
        std::cout << i << ", ";
        compareVecDictWQVecDict(maxValue, i);
        std::cout << std::endl;
    }
//    testWeaklyQueueishVecDict();

}
