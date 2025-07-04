#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = opt<int>(1);
    int r = opt<int>(2);
    rnd.setSeed(r);
    string s = "[a-z]{" + to_string(n) + "}";
    cout << rnd.next(s) << '\n';
}