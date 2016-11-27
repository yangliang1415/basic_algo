/*
 * date: 20151018
 * author: yangliang
 *
 * input num, output matrix like below
 *
 * n = 2 
 * 1 2 
 * 4 3
 *
 * n = 3
 * 1 2 3 
 * 8 9 4
 * 7 6 5
 */    

#include <iostream>     // cout
#include <iomanip>      // setw
#include <stdlib.h>     // atoi

using namespace std;

#define N 100

/*
 * print matrix
 * intput: n
 * output: matrix
 */
void print_matrix(int n) {
    int matrix[N][N];
    int row = 0;
    int col = 0;
    int i = 0;
    int j = 0;
    
    int count = 0;
    int cycle = (n + 1) / 2;
    for (int loop = 1; loop <= cycle; loop++) {
        // one row go
        for (row = loop, j = loop; j <= n - loop + 1; j++) {
            matrix[row][j] = ++count; 
        }
        // one col go
        for (col = n - loop + 1, i = loop + 1; i <= n - loop + 1; i++) {
            matrix[i][col] = ++count;
        }
        // one row bak
        for (row = n - loop + 1, j = n - loop; j >= loop; j--) {
            matrix[row][j] = ++count; 
        }
        // one col bak
        for (col = loop, i = n - loop; i >= loop + 1; i--) {
            matrix[i][col] = ++count;
        }
    }

    // print
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int main(int argc, char *argv[]) {
    int n;
    if (argc == 2) {
        n = atoi(argv[1]);
    } else {
        cout << "Usage: ./a.out num"<< endl;
        exit(0);
    }
    cout << n << endl;

    print_matrix(n);

    return 0;
}

