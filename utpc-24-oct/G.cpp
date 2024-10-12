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
    int u, v;
    ll c, e;
};

struct state {
    int u; ll d;
    bool operator<(const state &a) const { return d > a.d; }
};

int N, M, A, B;
vt<edge> adj[200005];
ll dc[200005], de[200005];
bool start[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> A >> B;
    for (int i = 0; i < M; i++) {
        int u, v; ll c, e; cin >> v >> u >> c >> e;
        adj[u].pb({u,v,c,e});
    }
    for (int i = 1; i < N; i++) {
        dc[i] = de[i] = 1e18;
    }
    priority_queue<state> pqc, pqe;
    for (int i = 0; i < A; i++) {
        int x; cin >> x;
        start[x] = 1;
    }
    for (int i = 0; i < B; i++) {
        int x; cin >> x;
        pqc.push({x,0});
        pqe.push({x,0});
        dc[x] = de[x] = 0;
    }
    while (!pqc.empty()) {
        state s = pqc.top();
        pqc.pop();
        for (edge e : adj[s.u]) {
            if (dc[e.v] > s.d+e.c) {
                dc[e.v] = s.d+e.c;
                pqc.push({e.v,dc[e.v]});
            }
        }
    }
    while (!pqe.empty()) {
        state s = pqe.top();
        pqe.pop();
        for (edge e : adj[s.u]) {
            if (de[e.v] > s.d+e.e) {
                de[e.v] = s.d+e.e;
                pqe.push({e.v,de[e.v]});
            }
        }
    }
    vt<ll> c, e;
    map<ll,int> mc, me;
    for (int i = 1; i < N; i++) {
        if (start[i]) {
            c.pb(dc[i]);
            mc[dc[i]]++;
            e.pb(de[i]);
            me[de[i]]++;
        }
    }
    sort(all(c));
    sort(all(e));
    // cout << "c: ";
    // for (int i = 0; i < sz(c); i++) {
    //     cout << c[i] << " ";
    // }
    // cout << endl;
    // cout << "e: ";
    // for (int i = 0; i < sz(e); i++) {
    //     cout << e[i] << " ";
    // }
    // cout << endl;
    int j = -1;
    ll lose = 0, tie = 0;
    for (int i = 0; i < sz(c); i++) {
        while (j+1 < sz(e) && e[j+1] < c[i]) j++;
        lose += j+1;
        tie += me[c[i]];
    }
    ll win = A*A-lose-tie;
    // cout << "win: " << win << " tie: " << tie << " lose: " << lose << endl;
    if (win > lose) {
        cout << "chicken" << endl;
    } else if (win < lose) {
        cout << "egg" << endl;
    } else {
        cout << "tie" << endl;
    }
    return 0;
}