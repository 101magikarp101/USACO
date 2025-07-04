#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(1, 1000, "N");
    inf.readSpace();
    int M = inf.readInt(1, 1000, "M");
    inf.readEoln();
    string s = "[SE.#]{" + to_string(M) + "}";
    int cntS = 0, cntE = 0;
    for (int i = 0; i < N; i++) {
        string row = inf.readToken(s, "row " + to_string(i));
        for (int j = 0; j < M; j++) {
            if (row[j] == 'S') {
                cntS++;
            } else if (row[j] == 'E') {
                cntE++;
            }
        }
        inf.readEoln();
    }
    ensure(cntS == 1);
    ensure(cntE == 1);
    inf.readEof();
}