#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    string s = ouf.readLine(".*", "contestant output");
    string t = ans.readLine(".*", "jury output");
    int n = s.size();
    int m = t.size();

    quitif(n != m, _wa, "bruh incorrect length");

    quitif(s != t, _wa, "ur wrong lmao");

    quitf(_ok, "UR HIM");
}
