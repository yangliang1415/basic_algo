/**
 * yangliang @ 20160108
 * ref: 442.findDuplicate
 */
#include <iostream>
#include <vector>

#include "util.h"


std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    int i = 0;
    int n = nums.size();
    while (i < n) {
        if (nums[i] != nums[nums[i]-1]) {
            std::swap(nums[i], nums[nums[i]-1]);
        } else {
            i++;
        }
    }
    std::vector<int> res;
    for (i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            res.push_back(i + 1);
        }
    }
    return res;
}


int main(int argc, char** argv) {
    std::vector<int> input;
    input.push_back(4);
    input.push_back(3);
    input.push_back(2);
    input.push_back(7);
    input.push_back(8);
    input.push_back(2);
    input.push_back(3);
    input.push_back(1);

    printVec(input);
    std::vector<int> res = findDisappearedNumbers(input);
    printVec(input);

    printVec(res);
}
