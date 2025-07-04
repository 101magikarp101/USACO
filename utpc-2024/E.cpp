#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N = 10;
map<double, vt<double>> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++) {
        double x, y; cin >> x >> y;
        m[x].push_back(y);
    }
    bool c = true;
    double mi = -1e9, ma = 1e9;
    set<double> s;
    for (auto i : m) {
        if (i.first==m.begin()->first) continue;
        if (i.first==m.rbegin()->first) continue;
        for (auto j : i.second) {
            s.insert(j);
        }
    }
    if (s.size() > 2) {
        c = false;
    }
    cout << (c ? "CASSETTE" : "VINYL") << endl;
    return 0;
}