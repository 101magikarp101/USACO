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
#define f first
#define s second
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

struct MCMF {
    using F = ll; using C = ll; // flow type, cost type
    struct Edge { int to; F flo, cap; C cost; };
    int N; vt<C> p, dist; vt<int> pre; vt<Edge> eds; vt<vt<int>> adj;
    void init(int _N) { N = _N;
        p.resize(N), dist.resize(N), pre.resize(N), adj.resize(N); }
    void addedge(int u, int v, F cap, C cost) { assert(cap >= 0); 
        adj[u].pb(sz(eds)); eds.pb({v,0,cap,cost}); 
        adj[v].pb(sz(eds)); eds.pb({u,0,0,-cost});
    } // use asserts, don't try smth dumb
    bool path(int s, int t) { // find lowest cost path to send flow through
        const C inf = numeric_limits<C>::max(); for (int i = 0; i < N; i++) dist[i] = inf;
        using T = pair<C,int>; priority_queue<T,vector<T>,greater<T>> todo; 
        todo.push({dist[s] = 0,s}); 
        while (sz(todo)) { // Dijkstra
            T x = todo.top(); todo.pop(); if (x.f > dist[x.s]) continue;
            for (auto &e : adj[x.s]) { const Edge& E = eds[e]; // all weights should be non-negative
                if (E.flo < E.cap && ckmin(dist[E.to],x.f+E.cost+p[x.s]-p[E.to]))
                    pre[E.to] = e, todo.push({dist[E.to],E.to});
            }
        } // if costs are doubles, add some EPS so you 
        // don't traverse ~0-weight cycle repeatedly
        return dist[t] != inf; // return flow
    }
    pair<F,C> calc(int s, int t) { assert(s != t);
        for (int i = 0; i < N; i++) for(int e = 0; e < sz(eds); e++) { const Edge& E = eds[e]; // Bellman-Ford
            if (E.cap) ckmin(p[E.to],p[eds[e^1].to]+E.cost); }
        F totFlow = 0; C totCost = 0;
        while (path(s,t)) { // p -> potentials for Dijkstra
            for (int i = 0; i < N; i++) p[i] += dist[i]; // don't matter for unreachable nodes
            F df = numeric_limits<F>::max();
            for (int x = t; x != s; x = eds[pre[x]^1].to) {
                const Edge& E = eds[pre[x]]; ckmin(df,E.cap-E.flo); }
            totFlow += df; totCost += (p[t]-p[s])*df;
            for (int x = t; x != s; x = eds[pre[x]^1].to)
                eds[pre[x]].flo += df, eds[pre[x]^1].flo -= df;
        } // get max flow you can send along path
        return {totFlow,totCost};
    }
};

int N, M, K;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    MCMF mf;
    mf.init(N+1);
    for (int i = 1; i <= M; i++) {
        int u, v, cap, cost; cin >> u >> v >> cap >> cost;
        mf.addedge(u, v, cap, cost);
    }
    mf.addedge(0, 1, K, 0);
    auto res = mf.calc(0, N);
    cout << (res.first == K ? res.second : -1) << endl;
    return 0;
}