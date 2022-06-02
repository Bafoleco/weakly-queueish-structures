#include <iostream>
#include <chrono>
#include "Dict.h"
#include "WeaklyQueueishDict.h"
#include "WeaklyQueueishVecDict.h"

template <class Key, class Value> int timeWeaklyQueueishVecDictIdeal(int numIters, std::vector<std::pair<Key, Value>> pairs) {
    WeaklyQueueishVecDict<Key, Value> weaklyQueueishVecDict(pairs);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numIters; i++) {
        for (int j = 0; j < pairs.size(); j++) {
            weaklyQueueishVecDict.query(j);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(end - start);
    return duration.count();
}

template <class Key, class Value> int timeVecDictIdeal(int numIters, std::vector<std::pair<Key, Value>> pairs) {
    VecDict<Key, Value> vecDict(pairs);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numIters; i++) {
        for (int j = 0; j < pairs.size(); j++) {
            vecDict.query(j);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(end - start);
    return duration.count();
}

//compares a VecDict with a WeaklyQueueishVecDict
void compareVecDictWQVecDict() {
    int maxValue = 1024 * 1024;
    int numIters = 10;

    std::vector<std::pair<int, std::string>> pairs;
    for (int i = 0; i < maxValue; i++) {
        pairs.emplace_back(i, std::to_string(i) + "s");
    }

    int weaklyQueueishTime = timeWeaklyQueueishVecDictIdeal(10, pairs);
    int regularTime = timeVecDictIdeal(10, pairs);

    std::cout << "weakly queueish time: " << weaklyQueueishTime << std::endl;
    std::cout << "regular time: " << regularTime << std::endl;
    std::cout << "ratio: " << (double) weaklyQueueishTime/ regularTime << std::endl;
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

    std::cout << "Time taken by regular structure: "
              << reg_duration.count() << " microseconds" << std::endl;


    std::cout << "ratio: " << (double) queueish_duration.count() / reg_duration.count() << std::endl;

    return 0;
}

int main() {

    compareVecDictWQVecDict();

//    testWeaklyQueueishVecDict();

}
