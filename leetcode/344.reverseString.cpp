#include <iostream>
#include <string>

using namespace std;


string reverseString(string s) {
    string result = s;
    int i = 0;
    int j = result.length() -1;
    while(i < j) {
        swap(result[i], result[j]);
        i++;
        j--;
    }
    return result;
}



int main() {
    cout << reverseString("hello") << endl;
    return 0;
}
