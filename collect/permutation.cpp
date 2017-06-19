/**
 * yangliang @20170530
 *
 * 全排列的 递归／非递归实现
 *
 * ref
 * http://blog.csdn.net/hackbuteer1/article/details/7462447
 */
#include <string>
#include <iostream>

using namespace std;


/**
 * 去重判断
 * 第i个数与第j个数交换时，要求[i,j)中没有与第j个数相等的数
 *
 * 理解
 * abcdc b和第2个c没必要交换，因为b和第1个c交换后得到ac[bdc], 后面都会重复
 */
bool is_swap(string s, int i, int j) {
    int len = s.length();
    for (int k = i; k < j; k++) {
        if (s[k] == s[j]) return false;
    }
    return true;
}


/**
 * 递归 无重复字符
 */
void permutation0(string s, int start) {
    int len = s.length();
    if (start == len - 1) {
        cout << s << endl;
    } else {
        for (int i = start; i < len; i++) {
            if (is_swap(s, start, i)) {
                swap(s[i], s[start]);
                permutation0(s, start+1);
                swap(s[i], s[start]);
            }
        }
    }
}

void permutation(string s) {
    permutation0(s, 0);
}

int main() {
    permutation("abb");
    return 0;
}
