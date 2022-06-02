#include <iostream>
#include <chrono>
#include "Dict.h"
#include "WeaklyQueueishDict.h"
#include "WeaklyQueueishVecDict.h"


template <class Key, class Value> void profileDict() {
    int maxValue = 1024 * 1024;
    std::initializer_list<std::pair<int, int>> initializer_list;

}

int testWeaklyQueueishVecDict() {
    int maxValue = 1024;

    std::vector<std::pair<int, std::string>> associations;
    for (int i = 0; i < maxValue; i++) {
        associations.emplace_back(i, std::to_string(i) + "s");
    }

    WeaklyQueueishVecDict<int, std::string> weaklyQueueishVecDict(associations);

    std::cout << "Built structure" << std::endl;

    for (int i = 0; i < maxValue; i++) {
        std::cout << weaklyQueueishVecDict.query(i).value() << std::endl;
    }

//    for (int i = 0; i < maxValue; i++) {
//        std::cout << weaklyQueueishDict.query(i).value() << std::endl;
//    }

    std::cout << "Starting queries:" << std::endl;

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

    testWeaklyQueueishVecDict();


//    int maxValue = 1024 * 1024 * 10;
//
//    std::vector<std::pair<int, std::string>> associations;
//    for (int i = 0; i < maxValue; i++) {
//        associations.emplace_back(i, std::to_string(i) + "s");
////        associations.emplace_back(i, i);
//    }
//
//    WeaklyQueueishDict<int, std::string> weaklyQueueishDict(associations);
////    WeaklyQueueishDict<int, int> weaklyQueueishDict(associations);
//
//    std::cout << "Built structure" << std::endl;
//
////    for (int i = 0; i < maxValue; i++) {
////        std::cout << weaklyQueueishDict.query(i).value() << std::endl;
////    }
////    for (int i = 0; i < maxValue; i++) {
////        std::cout << weaklyQueueishDict.query(i).value() << std::endl;
////    }
//
//    std::cout << "Starting queries:" << std::endl;
//
//    int iters = 4;
//    auto start = std::chrono::high_resolution_clock::now();
//    for (int i = 0; i < iters; i++) {
//        for (int j = 0; j < maxValue; j++) {
//            weaklyQueueishDict.query(j);
//        }
//    }
//    auto end = std::chrono::high_resolution_clock::now();
//    auto queueish_duration = duration_cast<std::chrono::microseconds>(end - start);
//
//    std::cout << "Time taken by weakly queueish structure: "
//         << queueish_duration.count() << " microseconds" << std::endl;
//
//    //for comparison
//    std::vector<std::pair<int, std::string>> associations2;
//    for (int i = 0; i < maxValue; i++) {
//        associations2.emplace_back(i, std::to_string(i) + "s");
//    }
//    Dict<int, std::string> dict(associations2);
//
//    start = std::chrono::high_resolution_clock::now();
//    for (int i = 0; i < iters; i++) {
//        for (int j = 0; j < maxValue; j++) {
//            dict.query(j);
//        }
//    }
//    end = std::chrono::high_resolution_clock::now();
//    auto reg_duration = duration_cast<std::chrono::microseconds>(end - start);
//
//    std::cout << "Time taken by regular structure: "
//              << reg_duration.count() << " microseconds" << std::endl;
//
//
//    std::cout << "ratio: " << (double) queueish_duration.count() / reg_duration.count() << std::endl;
//
//
//    std::cout << "sizeof: " << sizeof(Dict<int, std::string>) << std::endl;
//
//    return 0;

}
