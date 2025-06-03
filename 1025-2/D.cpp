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
#define repl(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define rrepl(i,a,b) for(ll i=a;i>=b;i--)
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

int T, N, M, L;
vt<int> adj[200005];
int col[200005];
int d[200005][2];
int l[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> N >> M >> L;
        rep(i,0,L) cin >> l[i];
        rep(i,1,N+1) adj[i].clear();
        rep(i,0,M) {
            int u, v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        rep(i,1,N+1) {
            col[i] = -1;
            d[i][0] = d[i][1] = INT_MAX;
        }
        queue<pii> q;
        q.push({1, 0});
        d[1][0] = 0;
        while (!q.empty()) {
            auto [u, dis] = q.front();
            q.pop();
            for (auto v : adj[u]) {
                if (d[v][(dis+1)%2] > dis+1) {
                    d[v][(dis+1)%2] = dis+1;
                    q.push({v, dis+1});
                }
            }
        }
        vt<int> e, o;
        int sume = 0, sumo = 0;
        rep(i,0,L) {
            if (l[i] % 2 == 0) {
                e.pb(l[i]);
                sume += l[i];
            } else {
                o.pb(l[i]);
                sumo += l[i];
            }
        }
        sort(all(e));
        sort(all(o));
        int mae = sume + sumo - (sz(o)%2==0 ? 0 : o[0]);
        int mao = -1;
        if (sz(o) > 0) {
            mao = sume + sumo - (sz(o)%2==1 ? 0 : o[0]);
        }
        rep(i,1,N+1) {
            bool res = 0;
            if (mae >= d[i][0]) {
                res = 1;
            }
            if (mao >= d[i][1]) {
                res = 1;
            }
            cout << res;
        }
        cout << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}