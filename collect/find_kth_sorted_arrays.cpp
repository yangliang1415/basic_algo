#include <vector>
#include <iostream>

using namespace std;


string print_vec(vector<int>& nums) {
    string res = "[";
    for (int i = 0; i < nums.size(); i++) {
        res += " " + to_string(nums[i]); 
    }
    res += " ]";
    return res;
}



int find_kth_sorted_arrays(vector<int>& nums1, vector<int>& nums2, int k) {
    //cout << "nums1:" << print_vec(nums1) << " nums2:" << print_vec(nums2) << " k=" << k << endl;

    int l1 = nums1.size();
    int l2 = nums2.size();

    if (l1 == 0) {
        return nums2[k-1];
    }
    if (l2 == 0) {
        return nums1[k-1];
    }
    if (k == 1) {
        return min(nums1[0], nums2[0]);
    }

    // odd and even
    if ((l1 & 1) ^ (l2 & 1)) {
        if (nums1[0] < nums2[0]) {
            vector<int> nums1_sub(nums1.begin()+1, nums1.end());
            return find_kth_sorted_arrays(nums1_sub, nums2, k-1);
        } else {
            vector<int> nums2_sub(nums2.begin()+1, nums2.end());
            return find_kth_sorted_arrays(nums1, nums2_sub, k-1);
        }
    }
    int a_mid;
    int b_mid;
    if (l1 & 1) {
        // odd and odd
        a_mid = l1 / 2;
        b_mid = l2 / 2;
    } else {
        // even and even
        a_mid = l1 / 2 - 1;
        b_mid = l2 / 2;
    }

    if (nums1[a_mid] <= nums2[b_mid]) {
        if (k <= a_mid + b_mid + 1) {
            vector<int> nums2_sub(nums2.begin(), nums2.begin()+b_mid);
            return find_kth_sorted_arrays(nums1, nums2_sub, k);
        } else {
            vector<int> nums1_sub(nums1.begin()+a_mid+1, nums1.end());
            return find_kth_sorted_arrays(nums1_sub, nums2, k-a_mid-1);
        }
    } else {
        if (k <= a_mid + b_mid + 1) {
            vector<int> nums1_sub(nums1.begin(), nums1.begin()+a_mid);
            return find_kth_sorted_arrays(nums1_sub, nums2, k);
        } else {
            vector<int> nums2_sub(nums2.begin()+b_mid+1, nums2.end());
            return find_kth_sorted_arrays(nums1, nums2_sub, k-b_mid-1);
        }
    }
    return 0;
}



int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(2);

    vector<int> b;
    b.push_back(3);
    b.push_back(4);

    int i = 2;
    for (int i = 1; i <= 10; i++)
        cout << find_kth_sorted_arrays(a, b, i) << endl;
    return 0;
}
