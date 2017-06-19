#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

string decodeString(string s) {
    stack<int> countStack;
    stack<string> resStack;

    int i = 0;
    int len = s.length();
    string res = "";
    while (i < len) {
        if (isDigit(s[i])) {
            int count = 0;
            while (isDigit(s[i])) {
                count = 10 * count + (s[i] - '0');
                i++;
            }
            countStack.push(count);
        } else if (s[i] == '[') {
            resStack.push(res);
            res = "";
            i++;
        } else if (s[i] == ']') {
            string temp = resStack.top();
            resStack.pop();
            int repeat = countStack.top();
            countStack.pop();
            for (int k = 0; k < repeat; k++) {
                temp += res;
            }
            res = temp;
            i++;
        } else {
            res += s[i++];
        }
    }
    return res;
}

int main() {
    cout << decodeString("3[a]2[bc]") << endl;
    cout << decodeString("2[abc]3[cd]ef") << endl;
    // 嵌套 case
    cout << decodeString("3[a2[c]]") << endl;
    return 0;
}
