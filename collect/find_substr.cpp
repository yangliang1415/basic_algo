#include <string>
#include <iostream>

using namespace std;

int find11(string s, int i) {
    while (i < s.length()-1) {
        if (s[i] == '1' && s[i+1] == '1') {
            return i;
        }
        i++;
    }
    return -1;
}


bool findEff11(string s) {
    int len = s.length();
    int i = 0;
    while (i < len) {
        int index = find11(s, i);
        // not contain 11
        if (index == -1) {
            return false;
        }
        // contain 11
        // 11
        if  (s.length() == 2) {
            cout << "heihei hit" << " " << "index=" << index << " ";
            return true;
        }
        // 11_
        if (index == 0 && index + 1 < len-1 && s[index+2] != '1') {
            cout << "start hit" << " " << "index=" << index << " ";
            return true;
        }
        // _11
        if (index + 1 == len - 1 && s[index - 1] != '1') {
            cout << "end hit" << " " << "index=" << index << " ";
            return true;
        }
        // _11_
        if (index - 1 > 0 && index + 2 < len - 1 && s[index-1] != '1' && s[index+2] != '1') {
            cout << "mid hit" << " " << "index=" << index << " ";
            return true;
        }
        i = index + 2;
    }
    return false;
}


int main() {
    string s;
    while (cin >> s) {
        cout << findEff11(s) << endl;
    }
    return 0;
}
