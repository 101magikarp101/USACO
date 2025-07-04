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
#define mset multiset
#define fi first
#define se second
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

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

int T, N, M;
set<int> adj[100005];

struct state {
    int a, b, c;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        for (int i = 0; i < M; i++) {
            int u, v; cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        int k = 0;
        vt<state> ans;
        for (int i = 1; i <= N; i++) {
            while (sz(adj[i]) >= 2) {
                int u = *adj[i].begin();
                adj[i].erase(u);
                int v = *adj[i].begin();
                adj[i].erase(v);
                adj[u].erase(i);
                adj[v].erase(i);
                ans.pb({i, u, v});
                k++;
                if (adj[u].count(v)) {
                    adj[u].erase(v);
                    adj[v].erase(u);
                } else {
                    adj[u].insert(v);
                    adj[v].insert(u);
                }
            }
        }
        vt<pii> v1;
        vt<int> v2;
        vt<bool> vis(N+1, 0);
        for (int i = 1; i <= N; i++) {
            if (vis[i]) continue;
            if (sz(adj[i]) == 1) {
                int u = *adj[i].begin();
                v1.pb({i, u});
                vis[i] = 1;
                vis[u] = 1;
            } else if (sz(adj[i]) == 0) {
                v2.pb(i);
                vis[i] = 1;
            }
        }
        if (sz(v1) != 0) {
            for (int i = 0; i < sz(v2); i++) {
                auto [a, b] = v1.back();
                v1.pop_back();
                ans.pb({a, b, v2[i]});
                k++;
                v1.pb({v2[i], a});
            }
            while (sz(v1) >= 2) {
                auto [a, b] = v1.back();
                v1.pop_back();
                auto [c, d] = v1.back();
                v1.pop_back();
                ans.pb({a, b, c});
                k++;
                v1.pb({a, c});
            }
        }
        cout << k << endl;
        for (auto [a, b, c] : ans) {
            cout << a << " " << b << " " << c << endl;
        }
    }
    return 0;
}