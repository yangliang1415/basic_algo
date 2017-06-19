#include <iostream>
#include <string>

using namespace std;


string reverseWords(string &s) {
    reverse(s.begin(), s.end());
    int len = s.length();
    int read = 0;
    int write = 0;
    int num_words = 0;
    while (read < len ) {
        if (s[read] != ' ') {
            int words_start = read;
            for ( ; read < len && s[read] != ' '; read++);
            // find one word: s[words_start:read-1], overrite to s[write:] and reverse
            int write_start = write;
            for (int i = words_start; i <= read-1; i++) {
                s[write++] = s[i];
            }
            reverse(s.begin() + write_start, s.begin() + write);
            // end overrite
            s[write++] = ' ';
            num_words++;
        }
        read++;
    }
    if (num_words) {
        s.resize(write-1);
    } else {
        s = "";
    }
    return s;
}


int main() {
    string s = "  ";
    cout << "-" << s << "-" << reverseWords(s) << "-"<< endl;

    s = "a";
    cout << "-" << s << "-" << reverseWords(s) << "-"<< endl;

    s = "   a   ";
    cout << "-" << s << "-" << reverseWords(s) << "-"<< endl;

    s = "a";
    cout << "-" << s << "-" << reverseWords(s) << "-"<< endl;


    s = "  i   ma a   iter  ";
    cout << "-" << s << "-" << reverseWords(s) << "-"<< endl;
    return 0;
}
