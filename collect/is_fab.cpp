#include<iostream>
#include<string>

using namespace std;

bool isFab0(int a, int b, string inputStr) {
    bool res = false;
    string genStr = to_string(a) + to_string(b);
    while (genStr.length() <= inputStr.length()) {
        genStr += to_string(a + b);
        if (genStr == inputStr) {
            res = true;
            break;
        }
        int temp = a;
        a = b;
        b = temp + b;
    }
    return res;
}


bool isFab(string s) {
    int len = s.length();
    if (len <= 2) return false;

    int k1_start = 0;
    int k1_end = k1_start;
    int k2_start = k1_end + 1;
    int k2_end = k2_start;

    int num1 = (s[k1_start] - '0');
    for (k1_end = 0; k1_end <= len - 3;) {
        k2_start = k1_end + 1;
        int num2 = (s[k2_start] - '0');
        for (k2_end = k2_start; k2_end <= len - 1;) {
            cout << "k1_start=" << k1_start << " k1_end=" << k1_end 
                 << " k2_start=" << k2_start << " k2_end=" << k2_end 
                 << " num1=" << num1 << " num2=" << num2 << " s=" << s << endl;
            if (isFab0(num1, num2, s)) {
                return true;
            }
            num2 = 10 * num2 + (s[++k2_end] - '0');
        }
        num1 = 10 * num1 + (s[++k1_end] - '0');
    }
    return false;
}


int main() {
    string s = "";

    s = "112358";
    cout << isFab(s) << endl;

    s = "100101201302";
    cout << isFab(s) << endl;


    s = "112211221122";
    cout << isFab(s) << endl;
}
