#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
ll a[2005];

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        DSU dsu(N+1);
        vt<pii> ans;
        for (int m = N-1; m >= 1; m--) {
            vt<int> v(N+1, 0);
            for (int i = 1; i <= N; i++) {
                if (dsu.get(i) == i) {
                    int b = a[i]%m;
                    if (v[b]==0) {
                        v[b] = i;
                    } else {
                        dsu.unite(i, v[b]);
                        ans.push_back({i, v[b]});
                        break;
                    }
                }
            }
        }
        bool good = 1;
        for (int i = 1; i <= N; i++) {
            if (dsu.get(i) != dsu.get(1)) {
                good = 0;
                break;
            }
        }
        if (good) {
            cout << "YES" << endl;
            reverse(ans.begin(), ans.end());
            for (auto p : ans) {
                cout << p.x << " " << p.y << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}