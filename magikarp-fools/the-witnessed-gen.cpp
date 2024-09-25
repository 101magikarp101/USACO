#include "testlib.h"
#include <iostream>
#include <vector>
#include <chrono>
#define vt vector
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int N = opt<int>(1);
    int M = opt<int>(2);
    int mode = opt<int>(3);
    int p = opt<int>(4);
    int r = opt<int>(5);
    //set seed to current millis
    rnd.setSeed(r);
    cout << N << ' ' << M << '\n';
    vt<vt<char>> b(N, vt<char>(M, '.'));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (rnd.next(1, 100) <= p) {
                b[i][j] = '#';
            } else {
                b[i][j] = '.';
            }
        }
    }
    if (mode == 0) {
        b[0][0] = 'S';
        b[N-1][M-1] = 'E';
    } else {
        int si = rnd.next(0, N-1);
        int sj = rnd.next(0, M-1);
        int ei = rnd.next(0, N-1);
        int ej = rnd.next(0, M-1);
        while (si == ei && sj == ej) {
            ei = rnd.next(0, N-1);
            ej = rnd.next(0, M-1);
        }
        b[si][sj] = 'S';
        b[ei][ej] = 'E';
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << b[i][j];
        }
        cout << '\n';
    }
}