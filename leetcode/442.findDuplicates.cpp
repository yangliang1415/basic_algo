/**
 * yangliang @ 20161226
 * ref: top solutions
 */
#include <iostream>
#include <vector>

#include "util.h"


/**
 * [4,3,2,7,8,2,3,1]
 * 
 * 分析: 如果不缺数字，排序后，a[i] == i+1, for i in [0, n-1] 
 * 有的数字出现2次后，有数字缺失。如果排好序，那些缺失数字的地方会被重复出现的数字给占位。
 *
 * 所以解决方案如下
 * - "排序"
 *   遍历i，将a[i]放到他应该在的位置a[a[i]-1]
 *
 * - 遍历
 *   找到a[i] != i+1 的i，i位置上的数字a[i]便是出现2次的数字
 */
std::vector<int> findDuplicates(std::vector<int>& nums) {
    int i = 0;
    int n = nums.size();
    while (i < n) {
        if (nums[i] != nums[nums[i] - 1]) {
            std::swap(nums[i], nums[nums[i] - 1]);
        } else {
            i++;
        }
    }
    std::vector<int> res;
    for (i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            res.push_back(nums[i]);
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
    std::vector<int> res = findDuplicates(input);
    printVec(input);

    printVec(res);
}
