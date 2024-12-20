#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)((x).size())
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define each(i,a) for(auto &i:a)
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

int T, N;
int out[200005];
vt<int> in[200005];
bool vis[200005];
bool cyc[200005];

struct state {
    int u, d;
};

void solve(int u) {
    set<int> s;
    for (int n = u; ; n = out[n]) {
        if (s.count(n)) {
            int v = n;
            while (1) {
                cyc[v] = 1;
                v = out[v];
                if (v == n) break;
            }
            break;
        }
        if (vis[n]) break;
        vis[n] = 1;
        s.insert(n);
    }
}

int get(int u) {
    int res = 0;
    for (int v : in[u]) {
        res+=get(v);
    }
    return ++res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        rep(i,1,N+1) {
            in[i].clear();
            vis[i] = 0;
            cyc[i] = 0;
        }
        // cout << "N: " << N << endl;
        rep(i,1,N+1) {
            cin >> out[i];
            in[out[i]].pb(i);
        }
        rep(i,1,N+1) {
            if (!vis[i]) {
                solve(i);
            }
        }
        int ans = 2;
        rep(i,1,N+1) {
            if (cyc[i]) {
                for (int v : in[i]) {
                    if (!cyc[v]) {
                        ckmax(ans, get(v)+2);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}