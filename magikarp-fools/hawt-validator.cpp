#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    string s = inf.readString("\\S*", "s");
    inf.readEoln();
    ensuref(s.size() == 4, "bruh incorrect length");
    inf.readEof();
}
