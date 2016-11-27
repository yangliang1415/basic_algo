#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


#define _DEBUG
#define INT_MIN     -2147483648
#define INT_MAX      2147483647

/**
 * case: 0 1 12 123
 *
 */
int myAtoi(string str) {
    int len = str.length();
    int i = 0;

    int num_unlogic = 0;
    bool is_negative = false;
    while (!(str[i] >= '0' && str[i] <= '9') && i < len) {
        if (str[i] != ' ') num_unlogic += 1;
        if (str[i] == '-') is_negative = true; 
        if (str[i] == '+') is_negative = false; 
        i++;
    }
    if (num_unlogic > 1) return 0;
    if (i > 0 && num_unlogic == 1 &&  (str[i-1] != '-' && str[i-1] != '+')) return 0;


    int j = i;
    while (str[j] >= '0' && str[j] <= '9' && j < len) {
        j++;
    }
#ifdef _DEBUG
    cout << str << " " << i << " " << j << endl;
#endif

    int index = i;
    int res = 0;
    while (index < j) {
        int num = str[index] - '0';

        if (is_negative) {
            if ( -res < (INT_MIN + num) / 10){
                return INT_MIN;
            }
        } else {
            if (res > (INT_MAX - num) / 10) {
                return INT_MAX;
            }
        }

        res = 10 * res + num;
#ifdef _DEBUG
        cout << "index:" << index << "\tnum:" << num << "\tres:" << res << endl;
#endif
        index++;
    }
    res = is_negative ? -res :res;
    return res;
}

int main () {
    string str = "   010";
    cout << str << "\t" << myAtoi(str) << endl;
    /*
    while (cin >> str) {
        cout << str << "\t" << myAtoi(str) << endl;
    }
    */
    return 0;
}
