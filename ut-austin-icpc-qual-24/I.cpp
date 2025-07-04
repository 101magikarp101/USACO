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

struct trip {
    int x, y, z;
};

int N, M, Q;
int a[405];
set<int> b;
map<int,int> hot, cold;
int dh[405][405], dc[405][405];
vt<int> hotu[405], coldu[405];
vt<trip> qh[405], qc[405];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        b.insert(a[i]);
    }
    int cnt = 1;
    for (auto x : b) {
        cold[x] = cnt++;
    }
    cnt = 1;
    for (auto x : b) {
        hot[x] = sz(b)-cnt+1;
        cnt++;
    }
    for (int i = 1; i <= N; i++) {
        hotu[hot[a[i]]].pb(i);
        coldu[cold[a[i]]].pb(i);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dh[i][j] = 1e9;
            dc[i][j] = 1e9;
        }
    }
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        dh[u][v] = w;
        dh[v][u] = w;
        dc[u][v] = w;
        dc[v][u] = w;
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, v, k, t; cin >> u >> v >> k >> t;
        if (t==1) {
            qh[k].pb({u,v,i});
        } else {
            qc[k].pb({u,v,i});
        }
    }
    vt<int> ans(Q);
    for (int ii = 1; ii <= N; ii++) {
        for (int k : hotu[ii]) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (dh[i][k] != 1e9 && dh[k][j] != 1e9) {
                        dh[i][j] = min(dh[i][j], dh[i][k]+dh[k][j]);
                    }
                }
            }
        }
        for (int k : coldu[ii]) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (dc[i][k] != 1e9 && dc[k][j] != 1e9) {
                        dc[i][j] = min(dc[i][j], dc[i][k]+dc[k][j]);
                    }
                }
            }
        }
        for (trip q : qh[ii]) {
            ans[q.z] = dh[q.x][q.y];
        }
        for (trip q : qc[ii]) {
            ans[q.z] = dc[q.x][q.y];
        }
    }
    for (int i = 0; i < Q; i++) {
        cout << (ans[i]==1e9?-1:ans[i]) << endl;
    }
    return 0;
}