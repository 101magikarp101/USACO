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

struct state {
    int u, c;
};

int N;
int vis[200005];
vt<int> adj[200005];
int out[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        out[i] = x;
        adj[i].pb(x);
        adj[x].pb(i);
        vis[i] = -1;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (vis[i] == -1) {
            int tot = 0;
            int cnt = 0;
            vis[i] = 1;
            queue<state> q;
            q.push({i, 1});
            while (!q.empty()) {
                state u = q.front();
                tot++;
                cnt += u.c;
                q.pop();
                for (int v : adj[u.u]) {
                    if (vis[v] == -1) {
                        vis[v] = u.c^1;
                        q.push({v, u.c^1});
                    }
                }
            }
            cout << "i = " << i << " cnt = " << cnt << " tot = " << tot << endl;
            if (tot == 1) {
                ans++;
            } else {
                ans += min(cnt, tot-cnt);
            }
        }
    }
    cout << ans << endl;
    return 0;
}