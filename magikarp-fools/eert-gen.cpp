#include "testlib.h"
#include <iostream>
#define vt vector
using namespace std;
struct pii {
    int x, y;
};

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = opt<int>(1);
    int r = opt<int>(2);
    rnd.setSeed(r);
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << rnd.next(-9, 9);
        if (i < n-1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
    //generate a random tree with prufer code
    vt<int> vec;
    for (int i = 1; i <= n-2; i++) {
        vec.push_back(rnd.next(1, n));
    }
    vt<pii> edges;
    vt<int> deg(n+1, 1);
    for (int i : vec) {
        deg[i]++;
    }
    for (int i : vec) {
        for (int j = 1; j <= n; j++) {
            if (deg[j] == 1) {
                edges.push_back({i, j});
                deg[i]--;
                deg[j]--;
                break;
            }
        }
    }
    int last = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            if (last == 0) {
                last = i;
            } else {
                edges.push_back({last, i});
                break;
            }
        }
    }
    shuffle(edges.begin(), edges.end());
    for (pii p : edges) {
        cout << p.x << " " << p.y << endl;
    }
}