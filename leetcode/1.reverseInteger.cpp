#include <iostream>
#include <vector>
#include <cmath>
//#include <climit>

//#define INT_MAX  2147483647  
//#define INT_MIN  (-INT_MAX - 1)

int reverse(int x) {
    int res = 0;
    while (x) {
        int num = x%10;
        if (res > INT_MAX/10 || res < INT_MIN/10) {
            return 0;
        }
        res = res*10 + num;
        x /= 10;
    }

    return res;
}


int main() {
    int input_num = 0;
    while (std::cin >> input_num) {
        std::cout << input_num << "\t" << reverse(input_num) << std::endl;
    }

    return 0;
}
