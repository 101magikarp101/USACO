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
    int seed = opt<int>(13);
    random_t rnd;
    rnd.setSeed(seed);
    int N = rnd.next(minn, maxn);
    double m = rnd.next(minm, maxm)/100.0;
    int M = N*(N-1)/2*m;
    int K = rnd.next(mink, maxk);
    cout << N << " " << M << " " << K << endl;
    set<pair<int, int>> edges;
    for (int i = 0; i < M; i++) {
        int u, v;
        do {
            u = rnd.next(1, N);
            v = rnd.next(1, N);
        } while (u == v || edges.count({u, v}));
        edges.insert({u, v});
        edges.insert({v, u});
        cout << u << " " << v << endl;
    }
}