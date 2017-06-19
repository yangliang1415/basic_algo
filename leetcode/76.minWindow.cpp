#include <string>
#include <iostream>
#include <vector>

using namespace std;


string minWindow(string s, string t) {
    vector<int> statis(128, 0);
    for (int i = 0; i < t.length(); i++) {
        statis[t[i]]++;
    }

    int counter = t.size();
    int begin = 0;
    int end = 0;
    int d = INT_MAX;
    int head = 0;

    while (end < s.size()) {
        // 检查s当前字符是否命中t中字符. 
        //      statis[s[end]]>0: 表示命中
        //      counter: check whether the substring is valid
        // statis[s[end]]--
        // end++
        if (statis[s[end++]]-- > 0) counter--;

        cout << "counter=" << counter << " begin=" << begin << " end=" << end << " d=" << d << endl;

        // counter=0表示t[begin:end]包含s
        while (counter == 0) {
            // 当前最优解保存
            if (end - begin < d) d = end - (head = begin);
            // 左指针向右移动，寻找最有解.  statis[s[begin]] == 0表示左指的字符不可跳过，会破坏包含性，于是将counter++
            // statis[s[begin]] == 0; statis[s[begin]]++; begin++
            if (statis[s[begin++]]++ == 0) {
                counter++;
                cout << "--counter=" << counter << " begin=" << begin << " end=" << end << " d=" << d << endl;
            }
        }
    }
    return d == INT_MAX ? "" : s.substr(head, d);
}


int main() {
    cout << minWindow("debancab", "abc") << endl;
    return 0;
}
