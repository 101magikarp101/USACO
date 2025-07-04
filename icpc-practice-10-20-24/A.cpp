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

int N, M;
vt<string> nam;
umap<string, int> id;
vt<int> adj[105];
int up[105][7];
int d[105];

void add(string s) {
    if (id.count(s)) return;
    id[s] = sz(nam);
    nam.pb(s);
}

void dfs(int u, int dep) {
    d[u] = dep;
    for (int v : adj[u]) {
        dfs(v, dep+1);
    }
}

int lift(int u, int k) {
    for (int i = 0; i < 7; i++) {
        if (k & (1<<i)) {
            u = up[u][i];
        }
    }
    return u;
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    u = lift(u, d[u]-d[v]);
    if (u == v) return u;
    for (int i = 6; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

string ordinal(int x) {
    string s = to_string(x);
    if (x >= 11 && x <= 13) return s+"th";
    if (x%10 == 1) return s+"st";
    if (x%10 == 2) return s+"nd";
    if (x%10 == 3) return s+"rd";
    return s+"th";
}

string child(int d) {
    if (d == 1) return "child";
    string s = "";
    for (int i = 0; i < d-2; i++) {
        s += "great ";
    }
    s += "grandchild";
    return s;
}

string sib(int d) {
    if (d == 1) return "siblings";
    else return ordinal(d-1) + " cousins";
}

string cous(int ds, int dt) {
    if (ds > dt) swap(ds, dt);
    string s = ordinal(ds-1) + " cousins, " + to_string(dt-ds) + " time" + (dt-ds==1?"":"s") + " removed";
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 7; j++) {
            up[i][j] = -1;
        }
    }
    for (int i = 0; i < N; i++) {
        string p; cin >> p;
        add(p);
        int pp = id[p];
        int s; cin >> s;
        for (int j = 0; j < s; j++) {
            string c; cin >> c;
            add(c);
            int cc = id[c];
            adj[pp].pb(cc);
            up[cc][0] = pp;
        }
    }
    int head = 0;
    while (up[head][0] != -1) {
        head = up[head][0];
    }
    dfs(head, 0);
    for (int j = 1; j < 7; j++) {
        for (int i = 0; i < sz(nam); i++) {
            if (up[i][j-1] != -1) {
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
    }
    while (M--) {
        string s, t; cin >> s >> t;
        int ss = id[s], tt = id[t];
        int l = lca(ss, tt);
        int ds = d[ss]-d[l], dt = d[tt]-d[l];
        if (ds == 0) {
            cout << t << " is the " << child(dt) << " of " << s << endl;
        } else if (dt == 0) {
            cout << s << " is the " << child(ds) << " of " << t << endl;
        } else if (ds == dt) {
            cout << s << " and " << t << " are " << sib(ds) << endl;
        } else {
            cout << s << " and " << t << " are " << cous(ds, dt) << endl;
        }
    }
    return 0;
}