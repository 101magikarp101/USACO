#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = opt<int>(1);
    int m = opt<int>(2);
    int r = opt<int>(3);
    rnd.setSeed(r);
    int p = rnd.next(1, 100);
    cout << n << " " << m << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rnd.next(1, 100) <= p) cout << "#";
            else cout << ".";
        }
        cout << endl;
    }
}