#include <bits/stdc++.h>
#include "testlib.h"
#define vt vector

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 200'000, "n");
    inf.readSpace();
    int q = inf.readInt(1, 200'000, "q");
    inf.readEoln();
    for(int i = 0; i < n; i++) {
        int t = inf.readInt(1, 2, "k_i");
        inf.readSpace();
        if (t == 1) {
            inf.readInt(1, 360, "x_i");
        } else {
            inf.readInt(1, 1'000'000'000, "y_i");
        }
        inf.readEoln();
    }
    for(int i = 0; i < q; i++) {
        inf.readInt(1, n, "l_i");
        inf.readSpace();
        inf.readInt(1, n, "r_i");
        inf.readEoln();
    }
    inf.readEof();
}