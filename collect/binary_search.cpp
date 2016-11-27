#include <iostream>


using namespace std;


int binary_search_0(int array[], int n, int target) {
    if (array == NULL || n <= 0) {
        return -1;
    }

    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (array[mid] == target) {
            return mid;
        } else if (array[mid] > target) {
            high = mid - 1;
        } else {
            // array[mid] < target
            low = mid + 1;
        }
    }

    return -1;
}



int main(int argc, char *argv[]) {
    int array[] = {1, 2, 3, 4, 5};
    int n = 5;

    cout <<  binary_search_0(array, n, -12) << endl;

    return 0;
}
