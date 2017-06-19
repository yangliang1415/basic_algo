#include<vector>
#include<iostream>

#include "util.h"

using namespace std;


int remove_duplicates(vector<int>& nums) {
    int i = 0;
    int j = 1;
    while (j < nums.size()) {
        if (nums[j] != nums[i]) {
            nums[++i] = nums[j];
        } else {
            if (i==0) nums[++i] = nums[j];
            if (i>0 && nums[i-1] != nums[i]) nums[++i] = nums[j];
        }
        j++;
    }
    return i+1;
}



int main() {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);

    remove_duplicates(vec);

    printVec(vec);
    return 0;
}
