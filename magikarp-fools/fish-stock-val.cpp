#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int x = 0, o = 0;
    for (int i = 0; i < 3; i++) {
        string s = inf.readToken("[.XO]{3}", "board row");
        for (int j = 0; j < 3; j++) {
            if (s[j] == 'X') {
                x++;
            } else if (s[j] == 'O') {
                o++;
            }
        }
        inf.readEoln();
    }
    inf.readEof();
    ensure(x == o || x == o+1);
}