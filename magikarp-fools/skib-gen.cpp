#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = opt<int>(1);
    int r = opt<int>(2);
    rnd.setSeed(r);
    for (int i = 0; i < 2; i++) {
        int len = rnd.next(2, 20);
        for (int j = 0; j < len; j++) {
            cout << char('0' + rnd.next(0, 9));
        }
        cout << endl;
    }
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        int len = rnd.next(2, 20);
        for (int j = 0; j < len; j++) {
            cout << char('0' + rnd.next(0, 9));
        }
        cout << endl;
    }
}