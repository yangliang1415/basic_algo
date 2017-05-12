#ifndef _UTIL
#define _UTIL

#include <iostream>
#include <vector>


void printVec(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int findMinIndex(std::vector<int> vec) {
    int minIndex = 0;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] < vec[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int findMaxIndex(std::vector<int> vec) {
    int maxIndex = 0;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] > vec[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

#endif
