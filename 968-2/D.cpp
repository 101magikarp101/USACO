#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
struct pii {
    int x, y;
    bool operator<(const pii &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pii &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pii &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pii &a) const { return x != a.x || y != a.y; }
    pii operator+(const pii &a) const { return {x+a.x, y+a.y}; }
    pii operator-(const pii &a) const { return {x-a.x, y-a.y}; }
    pii operator*(const int &a) const { return {x*a, y*a}; }
    pii operator/(const int &a) const { return {x/a, y/a}; }
};
struct pll {
    ll x, y;
    bool operator<(const pll &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pll &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pll &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pll &a) const { return x != a.x || y != a.y; }
    pll operator+(const pll &a) const { return {x+a.x, y+a.y}; }
    pll operator-(const pll &a) const { return {x-a.x, y-a.y}; }
    pll operator*(const ll &a) const { return {x*a, y*a}; }
    pll operator/(const ll &a) const { return {x/a, y/a}; }
};

ll T, N, M;
set<ll> a[200005];
pll b[200005];
multiset<ll> c[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            a[i].clear();
            ll m; cin >> m;
            for (int j = 0; j < m; j++) {
                ll x; cin >> x;
                a[i].insert(x);
            }
        }
        ll ma = -1;
        for (int i = 0; i < N; i++) {
            ll mex = 0;
            while (a[i].find(mex)!=a[i].end()) {
                mex++;
            }
            ll l = mex;
            a[i].insert(mex);
            while (a[i].find(mex)!=a[i].end()) {
                mex++;
            }
            ll r = mex;
            b[i] = {l, r};
            ma = max(ma, r);
        }
        sort(b, b+N, [](pll x, pll y) {
            return x.y > y.y;
        });
        for (ll i = 0; i <= ma; i++) {
            c[i].clear();
        }
        for (int i = 0; i < N; i++) {
            ll res = b[i].y;
            if (sz(c[b[i].y])>0) {
                res = max(res, *c[b[i].y].rbegin());
            }
            c[b[i].x].insert(res);
            if (sz(c[b[i].x])>2) {
                c[b[i].x].erase(c[b[i].x].begin());
            }
        }
        ll best = 0;
        for (ll i = 0; i <= ma; i++) {
            if (sz(c[i])>0) best = max(best, i);
            if (sz(c[i])>1) best = max(best, *c[i].rbegin());
        }
        ll ans = 0;
        for (ll i = 0; i <= min(ma, M); i++) {
            ll res = max({best, i});
            if (sz(c[i])>0) {
                res = max(res, *c[i].rbegin());
            }
            ans += res;
        }
        if (M>ma) {
            ans += (ma+1+M)*(M-ma)/2;
        }
        cout << ans << endl;
    }
    return 0;
}