#include <bits/stdc++.h>
#include "testlib.h"
#define vt vector
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100000, "n");
    inf.readSpace();
    int k = inf.readInt(4,7,"k");
    inf.readEoln();
    for (int i = 0; i < n; i++) {
        int a = inf.readInt(1, (1<<k)-1, "a");
        inf.readEoln();
    }
    inf.readEof();
}