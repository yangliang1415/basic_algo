/**
 * yangliang @ 20161127
 */
#include <iostream>
#include <string>

//#define _DEBUG

/**
 * case study:
 * 1 2 3
 *   2 4
 * 1 4 7
 */
std::string add_two_string(const std::string& val1, const std::string& val2) {
    int len1 = val1.length();
    int len2 = val2.length();
    int i = len1 - 1;
    int j = len2 - 1;
    int add = 0;
    int num = 0;
    std::string result = "";
    // care add > 0 condition
    while (i >= 0 || j >= 0 || add > 0) {
        int num1 = 0;
        int num2 = 0;
        if (i >= 0) {
            num1 = val1[i] - '0';
        }
        if (j >= 0) {
            num2 = val2[j] - '0';
        }
        num = (num1 + num2+ add) % 10;
        add = (num1 + num2 + add) / 10;
#ifdef _DEBUG
        std::cout << "i=" << i << " j=" << j << " num1="<< num1 << " num2="<< num2 << " num="<< num <<  std::endl;
#endif
        i--;
        j--;
        result = std::to_string(num) + result;
    }
    return result;
}


void test(int num1, int num2) {
    std::string result_expect = std::to_string(num1 + num2);
    std::string result = add_two_string(std::to_string(num1), std::to_string(num2));
    if (result != result_expect) {
        std::cout << "test error: " << "num1=" << num1 << " num2=" << num2
            << " result_expect=" << result_expect << " result=" << result << std::endl;
    }
}


int main(int argc, char** argv) {
    test(1, 1);
    test(1234, 1);
    test(1, 1234);
    test(9, 1);
    test(1, 99);
    test(1, 999);
    test(2, 999);
    test(1, 0);
    test(22, 88);
    test(222, 888);
}
