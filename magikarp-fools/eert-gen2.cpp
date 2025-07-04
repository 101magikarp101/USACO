#include "testlib.h"
#include <iostream>
#include <chrono>
#define vt vector
struct pii {
    int x, y;
};
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = 20;
    cout << n << endl;
    rnd.setSeed(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i < n; i++) {
        cout << rnd.next(-1, 1);
        if (i < n-1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
    vt<pii> edges;
    for (int i = 2; i <= n; i++) {
        edges.push_back({1, i});
    }
    shuffle(edges.begin(), edges.end());
    for (pii p : edges) {
        cout << p.x << " " << p.y << endl;
    }
}