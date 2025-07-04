#include "testlib.h"
#include <iostream>
#define vt vector

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = opt<int>(1);
    int m = opt<int>(2);
    int r = opt<int>(3);
    rnd.setSeed(r);
    int p = rnd.next(1, 100);
    cout << n << " " << m << endl;
    vt<vt<char>> a(n, vt<char>(m, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rnd.next(1, 100) <= p) {
                a[i][j] = '#';
            }
        }
    }
    int x = rnd.next(0, n-1);
    int y = rnd.next(0, m-1);
    a[x][y] = 'S';
    int dx = x;
    int dy = y;
    while (dx == x && dy == y) {
        dx = rnd.next(0, n-1);
        dy = rnd.next(0, m-1);
    }
    a[dx][dy] = 'E';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}