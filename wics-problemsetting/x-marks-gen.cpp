#include "testlib.h"
#include <iostream>
#define vt vector

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n_min = opt<int>(1);
    int n_max = opt<int>(2);
    int q_min = opt<int>(3);
    int q_max = opt<int>(4);
    int p_min = opt<int>(5);
    int p_max = opt<int>(6);
    int y_min = opt<int>(7);
    int y_max = opt<int>(8);
    bool maxout = opt<bool>(9);
    int seed = opt<int>(10);
    random_t rnd;
    rnd.setSeed(seed);
    int n = rnd.next(n_min, n_max);
    int q = rnd.next(q_min, q_max);
    cout << n << " " << q << endl;
    int p = rnd.next(p_min, p_max);
    for(int i = 0; i < n; i++) {
        int hm = rnd.next(1, 100);
        if (hm <= p) {
            cout << "1 " << rnd.next(1, 360) << endl;
        } else {
            cout << "2 " << rnd.next(y_min, y_max) << endl;
        }
    }
    for(int i = 0; i < q; i++) {
        int l = rnd.next(1, n);
        int r = rnd.next(1, n);
        if (l > r) swap(l, r);
        if (maxout) {
            l = 1;
            r = n;
        }
        cout << l << " " << r << endl;
    }
}