#include <bits/stdc++.h>
#include "testlib.h"
#define vt vector

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(2, 200, "n");
    inf.readSpace();
    int m = inf.readInt(0, n*(n-1)/2, "m");
    inf.readSpace();
    int k = inf.readInt(1, 1'000'000, "k");
    inf.readEoln();

    set<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");
        inf.readEoln();
        ensure(u != v);
        ensure(!edges.count({u, v}));
        edges.insert({u, v});
        edges.insert({v, u});
    }
    inf.readEof();
}