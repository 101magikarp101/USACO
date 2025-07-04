#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(1, 16, "N");
    inf.readEoln();
    for (int i = 0; i < N; i++) {
        inf.readInt(1, 16, "a_i");
        if (i < N-1) {
            inf.readSpace();
        } else {
            inf.readEoln();
        }
    }
    inf.readEof();
}