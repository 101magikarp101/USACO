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

int T, N, M, Q;

struct edge {
    int u, v, w;
    bool operator<(const edge &a) const { return w < a.w; }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> N >> M >> Q;
        vt<vt<int>> d(N, vt<int>(N));
        rep(i,0,N) rep(j,0,N) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = 1e9;
        }
        vt<edge> es;
        rep(i,0,M) {
            int u, v, w; cin >> u >> v >> w;
            u--, v--;
            es.pb({u,v,w});
            d[u][v] = d[v][u] = 1;
        }
        rep(k,0,N) {
            rep(i,0,N) {
                rep(j,0,N) {
                    ckmin(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        sort(all(es));
        vt<vt<vt<int>>> ds = {d};
        rep(k,0,M) {
            int u = es[k].u, v = es[k].v;
            d[u][v] = d[v][u] = 0;
            rep(i,0,N) {
                rep(j,0,N) {
                    ckmin(d[i][j], d[i][u] + d[v][j]);
                    ckmin(d[i][j], d[i][v] + d[u][j]);
                }
            }
            ds.pb(d);
        }
        while (Q--) {
            int u, v, k; cin >> u >> v >> k;
            u--, v--;
            int l = 0, r = M;
            while (l < r) {
                int m = (l + r) / 2;
                if (ds[m][u][v] < k) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            cout << es[l-1].w << ' ';
        }
        cout << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}