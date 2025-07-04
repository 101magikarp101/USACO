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

int N;
vt<int> adj[100005];
ll tot[100005];
map<pii,int> edges;
map<pii,ll> ans;
map<int,ll>* maps[100005];
int col[100005];

void solve(int u, int p) {
    if (u != 1) {
        pii e = {u,p};
        if (e.x > e.y) swap(e.x,e.y);
        if (sz(adj[u]) == 1) {
            maps[u] = new map<int,ll>();
            auto &m = *maps[u];
            m[col[u]]++;
            ll res = tot[col[u]]-1;
            ans[e] = res;
            return;
        }
        vt<pair<map<int,ll>*,ll>> vec;
        for (int v : adj[u]) {
            if (v == p) continue;
            solve(v,u);
            pii ee = {u,v};
            if (ee.x > ee.y) swap(ee.x,ee.y);
            vec.pb({maps[v],ans[ee]});
        }
        // cout << "u " << u << " sz " << sz(vec) << endl;
        for (int i = 0; i < sz(vec); i++) {
            if (vec[i].first->size() > vec[0].first->size()) {
                swap(vec[0], vec[i]);
            }
        }
        ll res = vec[0].second;
        map<int,ll> &m = *vec[0].first;
        res -= m[col[u]]*(tot[col[u]]-m[col[u]]);
        m[col[u]]++;
        res += m[col[u]]*(tot[col[u]]-m[col[u]]);
        for (int i = 1; i < sz(vec); i++) {
            for (auto j : *vec[i].first) {
                int x = j.first;
                ll y = j.second;
                res -= m[x]*(tot[x]-m[x]);
                m[x]+=y;
                res += m[x]*(tot[x]-m[x]);
            }
        }
        // cout << "m" << endl;
        // for (auto x : m) {
        //     cout << x.first << " " << x.second << endl;
        // }
        ans[e] = res;
        maps[u] = &m;
    } else {
        for (int v : adj[u]) {
            if (v == p) continue;
            solve(v, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> col[i];
        tot[col[i]]++;
    }
    for (int i = 0; i < N-1; i++){
        int u, v; cin >> u >> v;
        if (u>v) swap(u,v);
        edges[{u,v}] = i;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    solve(1,0);
    vt<ll> res(N-1);
    for (auto x : ans) {
        res[edges[x.first]] = x.second;
    }
    for (ll i : res) {
        cout << i << endl;
    }
    return 0;
}