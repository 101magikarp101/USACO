#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = opt<int>(1);
    int k = opt<int>(2);
    int r = opt<int>(3);
    rnd.setSeed(r);
    cout << n << " " << k << endl;
    for (int i = 0; i < n; i++) {
        int a = rnd.next(1, (1<<k)-1);
        cout << a << endl;
    }
}