#include "testlib.h"
#include <iostream>
#define vt vector
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = opt<int>(1);
    int r = opt<int>(2);
    rnd.setSeed(r);
    cout << n << endl;
    vt<int> v;
    for (int i = 1; i <= 16; i++) {
        v.push_back(i);
    }
    shuffle(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        cout << v[i];
        if (i < n-1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}