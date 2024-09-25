#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};
struct ppii {
    pii x, y;
};

const int sz = 41;
char a[2*sz+1][2*sz+1];
int b[2*sz+1][2*sz+1];

struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    vt<ppii> v;
    for (int i = 0; i <= 2*sz; i++) {
        for (int j = 0; j <= 2*sz; j++) {
            if (i%2==0||j%2==0) a[i][j] = '#';
            else a[i][j] = '.';
            if (i%2==1&&j%2==1) {
                b[i][j] = cnt;
                cnt++;
            }
        }
    }
    for (int i = 1; i <= 2*sz; i+=2) {
        for (int j = 3; j <= 2*sz; j+=2) {
            v.push_back({{i,j-2}, {i,j}});
        }
    }
    for (int i = 3; i <= 2*sz; i+=2) {
        for (int j = 1; j <= 2*sz; j+=2) {
            v.push_back({{i-2,j}, {i,j}});
        }
    }
    rnd.setSeed(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(v.begin(), v.end());
    int sec = cnt;
    DSU d(cnt);
    for (ppii p : v) {
        if (!d.same_set(b[p.x.x][p.x.y], b[p.y.x][p.y.y])) {
            d.unite(b[p.x.x][p.x.y], b[p.y.x][p.y.y]);
            sec--;
            a[(p.x.x+p.y.x)>>1][(p.x.y+p.y.y)>>1] = '.';
            if (sec == 1) break;
        }
    }
    cout << 2*sz+1 << ' ' << 2*sz+1 << endl;
    a[1][1] = 'S';
    a[2*sz-1][2*sz-1] = 'E';
    for (int i = 0; i <= 2*sz; i++) {
        for (int j = 0; j <= 2*sz; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}