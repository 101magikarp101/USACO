#include <bits/stdc++.h>
#include "testlib.h"
#define vt vector

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 1000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 1000, "m");
    inf.readEoln();
    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        string s = inf.readToken(format("[.#SE]{%d}", m));
        for (int j = 0; j < m; j++) {
            if (s[j] == 'S') {
                start++;
            } else if (s[j] == 'E') {
                end++;
            }
        }
        inf.readEoln();
    }
    ensuref(start == 1, "There must be exactly one 'S'");
    ensuref(end == 1, "There must be exactly one 'E'");
    inf.readEof();
}