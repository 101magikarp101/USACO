#include <bits/stdc++.h>
#include "testlib.h"
#define vt vector

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(1, 100000, "N");
    inf.readEoln();
    for (int i = 0; i < N; i++) {
        inf.readInt(1, 1'000'000'000, "a_i");
        if (i < N-1) {
            inf.readSpace();
        } else {
            inf.readEoln();
        }
    }
    inf.readEof();
}