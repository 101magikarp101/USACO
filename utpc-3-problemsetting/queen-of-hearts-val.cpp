#include <bits/stdc++.h>
#include "testlib.h"
#define vt vector

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 200'000, "n");
    inf.readEoln();
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x = inf.readInt(1, 1'000'000'000, "a_i");
        if (s.count(x)) {
            quitf(_wa, "duplicate element %d", x);
        }
        s.insert(x);
        if (i < n-1) inf.readSpace();
    }
    inf.readEoln();
    inf.readEof();
    return 0;
}