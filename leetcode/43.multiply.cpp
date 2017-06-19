#include <iostream>
#include <string>
#include <vector>

using namespace std;


/**
 * case study:
 *    1 3 1
 *      1 5
 * -----------
 *    6 5 5
 *  1 3 1
 * --------
 *  1 9 6 5
 *
 * `num1[i] * num2[j]` will be placed at indices `[i + j`, `i + j + 1]` 
 *
 *  ref
 *  http://www.cnblogs.com/liujinhong/p/5999642.html
 */

string multiply(string num1, string num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    string result(len1 + len2, '0');
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j;
            int p2 = p1 + 1;

            int sum = mul + (result[p2] - '0');
            result[p1] += sum / 10;
            result[p2] = sum % 10 + '0';
        }
    }

    size_t start_pos = result.find_first_not_of('0');
    if (string::npos != start_pos) {
        return result.substr(start_pos); 
    }
    return "0";
}


int main(int argc, char** argv) {
    cout << multiply("15", "132") << endl;
    return 0;
}
