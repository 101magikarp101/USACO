#include <bits/stdc++.h>
#include "testlib.h"
#define vt vector

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(2, 50, "n");
    inf.readSpace();
    int m = inf.readInt(0, 100'000, "m");
    inf.readSpace();
    int k = inf.readInt(1, 1'000'000, "k");
    inf.readEoln();

    for (int i = 0; i < m; i++) {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");
        ensuref(u != v, "u and v must be different");
        inf.readSpace();
        int t = inf.readInt(1, 5, "t");
        inf.readEoln();
    }
    inf.readEof();
}