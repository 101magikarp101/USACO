#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, Q;
vt<int> adj[300005];
int sz[300005], p[300005], a[300005], rev[300005];
set<int> r[300005];
int tot = 0;

int check(int u) {
    // cout << "u: " << u << " res: " << (r[u].empty() || (*r[u].begin() == a[u]+1 && *r[u].rbegin()+sz[rev[*r[u].rbegin()]]-1 == a[u]+sz[u]-1) ? 1 : 0) << endl;
    return r[u].empty() || (*r[u].begin() == a[u]+1 && *r[u].rbegin()+sz[rev[*r[u].rbegin()]]-1 == a[u]+sz[u]-1);
}

void dfs(int u) {
    sz[u] = 1;
    r[u] = {};
    for (int v : adj[u]) {
        dfs(v);
        sz[u] += sz[v];
        r[u].insert(a[v]);
    }
    if (check(u)) {
        tot++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        tot = 0;
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        p[1] = 0;
        for (int i = 2; i <= N; i++) {
            int x; cin >> x;
            adj[x].push_back(i);
            p[i] = x;
        }
        for (int i = 1; i <= N; i++) {
            int x; cin >> x;
            rev[i] = x;
            a[x] = i;
        }
        dfs(1);
        // cout << "tot1: " << tot << endl;
        // cout << "b: " << endl;
        // for (int i = 1; i <= N; i++) {
        //     cout << b[i] << " ";
        // }
        // cout << endl;
        // cout << "tot: " << tot << endl;
        while (Q--) {
            int x, y; cin >> x >> y;
            int vx = rev[x], vy = rev[y];
            int px = p[vx], py = p[vy];
            set<int> s;
            s.insert(vx); s.insert(vy); s.insert(px); s.insert(py);
            for (int v : s) if (v>0) tot-=check(v);
            r[px].erase(x); r[py].erase(y);
            r[px].insert(y); r[py].insert(x);
            swap(a[vx], a[vy]);
            swap(rev[x], rev[y]);
            for (int v : s) if (v>0) tot+=check(v);
            // cout << "tot: " << tot << endl;
            cout << (tot==N?"YES":"NO") << endl;
        }
    }
    return 0;
}