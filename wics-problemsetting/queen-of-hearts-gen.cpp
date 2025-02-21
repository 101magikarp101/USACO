#include "testlib.h"
#include <iostream>
#define vt vector

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int mnn = opt<int>(1);
    int mxn = opt<int>(2);
    int mna = opt<int>(3);
    int mxa = opt<int>(4);
    int sus = opt<int>(5);
    int n = rnd.next(mnn, mxn);
    cout << n << endl;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x = rnd.next(mna, mxa);
        if (sus >= 100000 && i == 0) {
            x = mxa;
        }
        while (s.count(x)) {
            x = rnd.next(mna, mxa);
        }
        s.insert(x);
        cout << x;
        if (i < n-1) cout << " ";
    }
    cout << endl;
}