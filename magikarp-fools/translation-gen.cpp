#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = opt<int>(1);
    int r = opt<int>(2);
    rnd.setSeed(r);
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << rnd.next(1, 1'000'000'000);
        if (i < n - 1) {
            cout << ' ';
        } else {
            cout << '\n';
        }
    }
}