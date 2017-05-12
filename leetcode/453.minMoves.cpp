/**
 * yangliang @ 20160108
 */
#include <iostream>
#include <vector>

#include "util.h"


void move(std::vector<int>& nums, int index) {
    for (int i = 0; i < nums.size(); i++) {
        if (i != index) {
            nums[i]++;
        }
    }
}

// 复杂度太高
int minMoves(std::vector<int>& nums) {
    int moveNum = 0;
    int minIndex = findMinIndex(nums);
    int maxIndex = findMaxIndex(nums);
    while (nums[minIndex] < nums[maxIndex]) {
        move(nums, maxIndex);
        moveNum++;
        maxIndex = findMaxIndex(nums);
    }
    return moveNum;
}

// 计算得到结果。n-1个元素+1 等价于 1个元素－1
// moveNum = sum(nums) - minValue*size(nums)
int minMoves01(std::vector<int>& nums) {
    int moveNum = 0;
    int minIndex = findMinIndex(nums);
    for (int i = 0; i < nums.size(); i++) {
        moveNum += nums[i] - nums[minIndex];
    }
    return moveNum;
}


void test(std::vector<int> input) {
    int moveNum = 0;
    printVec(input);
    moveNum = minMoves01(input);
    std::cout << moveNum << std::endl;
    printVec(input);
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    std::vector<int> input;

    input.clear();
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    test(input);

    input.clear();
    input.push_back(0);
    input.push_back(2);
    input.push_back(5);
    test(input);

    input.clear();
    input.push_back(0);
    input.push_back(2);
    input.push_back(4);
    input.push_back(5);
    test(input);

    input.clear();
    input.push_back(1);
    input.push_back(2147483647);
    test(input);
}
