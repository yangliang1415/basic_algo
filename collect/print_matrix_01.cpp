/*
 * date: 20170601
 * author: yangliang
 */    

#include <iomanip>      // setw
#include <iostream>     // cout
#include <vector>

using namespace std;


void print_matrix(vector<vector<int> > nums) {
    int m = nums.size();
    int n = nums[0].size();
    for (int loop = 0; loop <= m + n - 2; loop++) {
        for (int i = min(loop, m-1); i >= 0 && loop - i < n; i--) {
            cout << setw(4) << nums[i][loop-i];
        }
        cout << endl;
    }
}


void print_matrix_primary(vector<vector<int> > nums) {
    int m = nums.size();
    int n = nums[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << nums[i][j] << " ";
        }
        cout << endl;
    }
}



vector<vector<int> > init_nums(int m, int n) {
    vector<vector<int> > res;
    int k = 0;
    for (int i = 1; i <= m; i++) {
        vector<int> one_vec;
        for (int j = 1; j <= n; j++) {
            one_vec.push_back(++k);
        }
        res.push_back(one_vec);
    }
    return res;
}


int main(int argc, char *argv[]) {
    vector<vector<int> > nums = init_nums(3, 14);
    print_matrix_primary(nums);
    cout << endl;
    print_matrix(nums);
}
