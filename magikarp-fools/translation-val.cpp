#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(2, 100000, "n");
    inf.readEoln();
    for (int i = 0; i < n; i++) {
        inf.readInt(1, 1'000'000'000, "a_i");
        if (i < n - 1) {
            inf.readSpace();
        } else {
            inf.readEoln();
        }
    }
    inf.readEof();
}