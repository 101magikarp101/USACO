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

struct edge {
    int u, v, w;
};

struct state {
    int u, d, m;
    bool operator<(const state &a) const {
        if (m == a.m) return d > a.d;
        return m < a.m;
    }
};

int N, M, Q;
int a[405];
set<int> b;
map<int,int> hot, cold;
vt<edge> adj[405];
int disth[405][405][405], distc[405][405][405];
int dh[405][405], dc[405][405];

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
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({u,v,w});
        adj[v].pb({v,u,w});
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                disth[i][j][k] = 1e9;
                distc[i][j][k] = 1e9;
            }
            dh[i][j] = 1e9;
            dc[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= N; i++) {
        priority_queue<state> pq;
        pq.push({i,0,1});
        disth[i][i][1] = 0;
        dh[i][i] = 1;
        while (!pq.empty()) {
            state u = pq.top();
            pq.pop();
            if (u.d > disth[i][u.u][u.m]) continue;
            if (u.u != i) u.m = max(u.m,hot[a[u.u]]);
            for (edge e : adj[u.u]) {
                int v = e.v, w = e.w;
                int d = u.d + w;
                if (d < disth[i][v][u.m] && u.m < dh[i][v]) {
                    disth[i][v][u.m] = d;
                    dh[i][v] = u.m;
                    pq.push({v,d,u.m});
                }
            }
        }
        pq.push({i,0,1});
        distc[i][i][1] = 0;
        dc[i][i] = 1;
        while (!pq.empty()) {
            state u = pq.top();
            pq.pop();
            if (u.d > distc[i][u.u][u.m]) continue;
            if (u.u != i) u.m = max(u.m,cold[a[u.u]]);
            for (edge e : adj[u.u]) {
                int v = e.v, w = e.w;
                int d = u.d + w;
                if (d < distc[i][v][u.m] && u.m < dc[i][v]) {
                    distc[i][v][u.m] = d;
                    dc[i][v] = u.m;
                    pq.push({v,d,u.m});
                }
            }
        }
    }
    // cout << "disth: " << endl;
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         for (int k = 1; k <= N; k++) {
    //             cout << disth[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    cin >> Q;
    while (Q--) {
        int u, v, k, t; cin >> u >> v >> k >> t;
        if (t==1) {
            int ans = 1e9;
            for (int i = 1; i <= k; i++) {
                ans = min(ans,disth[u][v][i]);
            }
            cout << (ans==1e9?-1:ans) << endl;
        } else {
            int ans = 1e9;
            for (int i = 1; i <= k; i++) {
                ans = min(ans,distc[u][v][i]);
            }
            cout << (ans==1e9?-1:ans) << endl;
        }
    }
    return 0;
}