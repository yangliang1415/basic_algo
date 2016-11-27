/**
 * yangliang @ 20161127
 * ref: http://www.cnblogs.com/grandyang/p/5507129.html
 */
#include <iostream>
#include <vector>
#include <set>


// o(n*n)
std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    if (nums1.size() == 0 || nums2.size() == 0) 
        return std::vector<int>();
    std::set<int> result0;
    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            if (nums1[i] == nums2[j]) {
                result0.insert(nums1[i]);
            }
        }
    }
    return std::vector<int>(result0.begin(), result0.end());
}


// o(n*log(n))
std::vector<int> intersection01(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::set<int> s1(nums1.begin(), nums1.end());
    std::set<int> result;
    for (int i = 0; i <= nums2.size(); i++) {
        if (s1.count(nums2[i])) {
            result.insert(nums2[i]);
        }
    }
    return std::vector<int>(result.begin(), result.end());
}


// o(n*log(n))
std::vector<int> intersection02(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> result;
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    int i = 0;
    int j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            if (result.empty() || result.back() != nums1[i]) {
                result.push_back(nums1[i]);
            }
            i++;
            j++;
        }
    }
    return result;
}


std::vector<int> intersection03(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::set<int> s1(nums1.begin(), nums1.end());
    std::set<int> s2(nums2.begin(), nums2.end());
    std::set<int> result;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(result, result.begin()));
    return std::vector<int>(result.begin(), result.end());
}


void print_vec(std::vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << "\t";
    }
    std::cout << std::endl;
}


int main(int argc, char** argv) {
    std::vector<int> nums1;
    nums1.push_back(3);
    nums1.push_back(1);
    nums1.push_back(2);

    std::vector<int> nums2;
    nums2.push_back(1);
    nums2.push_back(1);

    std::vector<int> res = intersection(nums1, nums2);
    print_vec(res);
}
