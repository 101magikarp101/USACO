#include <bits/stdc++.h>
#include "testlib.h"
#define vt vector

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 200000, "n");
    inf.readEoln();
    for (int i = 0; i < n; i++) {
        inf.readInt(1, 1000000000, "a_i");
        if (i < n-1) inf.readSpace();
    }
    inf.readEoln();
    inf.readEof();
    return 0;
}