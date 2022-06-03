#include <iostream>
#include <chrono>
#include "Dict.h"
#include "WeaklyQueueishDict.h"
#include "WeaklyQueueishVecDict.h"
#include <fstream>
#include <set>

template <class Key, class Value> int timeWeaklyQueueishVecDictIdeal(std::vector<std::pair<Key, Value>> pairs, std::vector<int> queries) {
    WeaklyQueueishVecDict<Key, Value> weaklyQueueishVecDict(pairs);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i : queries) {
        weaklyQueueishVecDict.query(i).value();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(end - start);
    return duration.count();
}

template <class Key, class Value> int timeVecDictIdeal(std::vector<std::pair<Key, Value>> pairs, std::vector<int> queries) {
    VecDict<Key, Value> vecDict(pairs, pairs.size());
    auto start = std::chrono::high_resolution_clock::now();
    for (int i : queries) {
        vecDict.query(i).value();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(end - start);
    return duration.count();
}

template <class A, class B> void printToCSV(std::string filename, std::vector<std::pair<A, B>> data) {
    std::ofstream file("test_results/" + filename);
    for (auto pair : data) {
        file << pair.first << ", " << pair.second << std::endl;
    }
    file.close();
}

//compares a VecDict with a WeaklyQueueishVecDict
void compareVecDictWQVecDictFile(int val, int k, std::ofstream& file) {
    int maxValue = val;
    int numIters = 20;

    std::vector<std::pair<int, std::string>> pairs;
    for (int i = 0; i < maxValue; i++) {
        pairs.emplace_back(i, std::to_string(i) + "s");
    }

    std::vector<int> queries;
    std::set<int> noQuery;
    srand(time(nullptr));

    while (noQuery.size() < k) {
        noQuery.insert(rand() % maxValue);
    }

    while (queries.size () < numIters * maxValue) {
        for (int i = 0; i < numIters; i++) {
            for (int j = 0; j < maxValue; j++) {
                if (queries.size() >= numIters * maxValue)
                    break;
                if (noQuery.count(j) == 0)
                    queries.push_back(j);
            }
        }
    }

    std::cout << "start count" << std::endl;
    int weaklyQueueishTime = timeWeaklyQueueishVecDictIdeal(pairs, queries);
    int regularTime = timeVecDictIdeal(pairs, queries);

    std::cout << "weakly queueish time: " << weaklyQueueishTime << std::endl;
    std::cout << "regular time: " << regularTime << std::endl;
    std::cout << "ratio: " << (double) weaklyQueueishTime/ regularTime << std::endl;
    file << weaklyQueueishTime << ", " << regularTime ;
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

void timePerfectWorkflowAtDifferentSizes() {
    std::vector<std::pair<int, int>> data;

    int numVals = 8;
    int numIters = 5;
    while (numVals < 1024 * 1024 * 16) {
        std::vector<std::pair<int, std::string>> pairs;
        for (int i = 0; i < numVals; i++) {
            pairs.emplace_back(i, std::to_string(i) + "s");
        }

        std::vector<int> queries;

        for (int i = 0; i < numIters; i++) {
            for (int j = 0; j < numVals; j++) {
                queries.push_back(j);
            }
        }

        int time = timeWeaklyQueueishVecDictIdeal(pairs, queries);
        data.emplace_back(numVals, time);
        numVals = numVals * 2;
    }
    printToCSV("perfect-workflow-diff-numelems.csv", data);
}

void testVaryingWorkflowComp() {
    std::ofstream file("../test_results/workflow-comp.csv");

    file << "Queueish value, weakly queueish, normal" << std::endl;
    int maxValue = 1024 * 1024 * 4;
    for (int i = 0; i < 100; i+=5) {
        file << i << ", ";
        compareVecDictWQVecDictFile(maxValue, i, file);
        file << std::endl;
    }
    compareVecDictWQVecDictFile(maxValue, maxValue-1, file);

    file.close();
}

void testWorstcaseComp() {
    std::ofstream file("../test_results/worsecase-comp.csv");

    file << "Queueish value, weakly queueish, normal" << std::endl;
    int maxValue = 1024 * 1024;
    file << maxValue << ", ";
    compareVecDictWQVecDictFile(maxValue, maxValue-1, file);
    file << std::endl;

    file.close();
}

void comparePerfectWorkFlow(int size, std::ofstream& file) {
    int maxValue = size;
    std::vector<std::pair<int, std::string>> pairs;
    for (int i = 0; i < maxValue; i++) {
        pairs.emplace_back(i, std::to_string(i) + "s");
    }

    std::vector<int> queries;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < maxValue; j++) {
            queries.push_back(j);
        }
    }

    int weaklyQueueishTime = timeWeaklyQueueishVecDictIdeal(pairs, queries);
    int regularTime = timeVecDictIdeal(pairs, queries);

    file << maxValue << ", ";
    file << weaklyQueueishTime << ", ";
    file << regularTime;
    file << std::endl;
}

int main() {
    std::ofstream file("../test_results/bestcase-comp.csv");
    file << "Num elements, weakly queueish, normal" << std::endl;
    for (int i = 8; i < 1024 * 1024 * 16; i*=2){
        comparePerfectWorkFlow(i, file);
    }
    file.close();
    // timePerfectWorkflowAtDifferentSizes();

    // testWeaklyQueueishVecDict();

    testVaryingWorkflowComp();


    // std::vector<std::pair<int, std::string>> pairs;
    // for (int i = 0; i < 1024 * 1024; i++) {
    //     pairs.emplace_back(i, std::to_string(i) + "s");
    // }

}
