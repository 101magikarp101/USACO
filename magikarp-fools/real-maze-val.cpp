#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(1, 1000, "N");
    inf.readSpace();
    int M = inf.readInt(1, 1000, "M");
    inf.readEoln();
    string p = "[.#a-zSE]{"+to_string(M)+"}";
    for (int i = 0; i < N; i++) {
        inf.readToken(p);
        inf.readEoln();
    }
    inf.readEof();
}