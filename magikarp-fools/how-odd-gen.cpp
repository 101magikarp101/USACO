#include "testlib.h"
#include <iostream>
#include <chrono>
#define vt vector
#define ll long long
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = 20;
    ll r = chrono::steady_clock::now().time_since_epoch().count();
    rnd.setSeed(r);
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        ll hm = 0;
        while (hm < 10'000'000'000'000'000LL) {
            hm = hm*10 + rnd.next(0, 4)*2+1;
        }
        hm = hm*10 + rnd.next(0, 4)*2;
        cout << hm;
        if (i < n-1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}