#include "testlib.h"
#include <iostream>
#define vt vector

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int minn = opt<int>("minn");
    int maxn = opt<int>("maxn");
    int minm = opt<int>("minm");
    int maxm = opt<int>("maxm");
    int mink = opt<int>("mink");
    int maxk = opt<int>("maxk");
    int maxt = opt<int>("maxt");
    int seed = opt<int>(15);
    random_t rnd;
    rnd.setSeed(seed);
    int N = rnd.next(minn, maxn);
    int M = rnd.next(minm, maxm);
    int K = rnd.next(mink, maxk);
    cout << N << " " << M << " " << K << endl;
    for (int i = 0; i < M; i++) {
        int u = rnd.next(1, N);
        int v = rnd.next(1, N);
        while (u == v) {
            u = rnd.next(1, N);
            v = rnd.next(1, N);
        }
        int t = rnd.next(1, maxt);
        cout << u << " " << v << " " << t << endl;
    }
}