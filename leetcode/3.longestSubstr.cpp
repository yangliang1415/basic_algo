/*
 * date: 20151022
 * author: yangliang
 *
 * 最长无重复字串
 * 全局最优，局部最优记录; 状态转移
 */
#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;


string printSet(set<char> char_set) {
    string res;
    for (set<char>::iterator iter = char_set.begin(); iter != char_set.end(); ++iter) {
        res.insert(res.end(), *iter);
    }
    return res;
}


int lengthOfLongestSubstring(string s) {
    int max_len = 0;
    int cur_len = 0;
    int start = 0;
    int end = 0;
    set<char> found_char;

    for (end = 0; end < s.length(); end++) {
        if (found_char.find((s[end])) == found_char.end()) {
            found_char.insert(s[end]);
            cur_len = end - start + 1;
            // cout << "not\t" << start << "\t" << end << "\t" << printSet(found_char) << endl;
        } else {
            // 更新 start
            // 注意：这里少插入了s[end], 同时也少删除了s[start], 它两相等，所以效果一样
            // 第一次大意，将下面两条语句顺序写反了，badcase: pwwkew
            while (s[start] != s[end]) {
                found_char.erase(s[start]);
                start++;
            }
            // cout << "yes\t" << start << "\t" << end << "\t" << printSet(found_char) << endl;
            start++;
            cur_len = end - start + 1;
        }

        max_len = max(cur_len, max_len);
    }

    return max_len;
}


/**
 * map<char, int> index_record记录每个出现字符的index
 *
 * L[i] = s[m...i], 表示以s[i]结尾的无重复字串
 * 考察s[i+1]
 * - s[i+1]未出现过 L[i] = s[m...i+1]
 * - s[i+1]出现过, m = max(m, index_record[i]+1), L[i] = s[m...i+1]
 *
 * ref
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/#/solutions
 */
int lengthOfLongestSubstring01(string s) {
    map<char, int> index_record;
    int longest = 0;
    int m = 0;
    for (int i = 0; i < s.length(); i++) {
        // 字符有重复
        if (index_record.find(s[i]) != index_record.end()) {
            m = max(m, index_record[s[i]] + 1);
        }
        index_record[s[i]] = i;
        longest = max(longest, i - m + 1);
    }
    return longest;
}


int main() {
    string s;
    while (cin >> s) {
        cout << lengthOfLongestSubstring(s) << "\t" << lengthOfLongestSubstring01(s) << endl;
    }
    return 0;
}
