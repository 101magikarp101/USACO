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
bool b[300005];
set<int> r[300005];
int tot = 0;

void dfs(int u) {
    sz[u] = 1;
    r[u] = {a[u]};
    for (int v : adj[u]) {
        dfs(v);
        sz[u] += sz[v];
        r[u].insert(*r[v].begin());
        r[u].insert(*r[v].rbegin());
    }
    // cout << "u: " << u << " sz: " << sz[u] << " r: " << r[u].x << " " << r[u].y << endl;
    if (*r[u].begin() == a[u] && *r[u].rbegin() == a[u]+sz[u]-1) {
        b[u] = 1;
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
            b[i] = 0;
            r[i].clear();
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
        while (Q--) {
            int x, y; cin >> x >> y;
            int vx = rev[x], vy = rev[y];
            int px = p[vx], py = p[vy];
            // cout << "x: " << x << " y: " << y << " vx: " << vx << " vy: " << vy << " px: " << px << " py: " << py << endl;
            if (px!=0) {
                r[px].erase(*r[vx].begin());
                r[px].erase(*r[vx].rbegin());
            }
            if (py!=0) {
                r[py].erase(*r[vy].begin());
                r[py].erase(*r[vy].rbegin());
            }
            r[vx].erase(a[vx]);
            r[vy].erase(a[vy]);
            r[vx].insert(a[vy]);
            r[vy].insert(a[vx]);
            if (px!=0) {
                r[px].insert(*r[vx].begin());
                r[px].insert(*r[vx].rbegin());
            }
            if (py!=0) {
                r[py].insert(*r[vy].begin());
                r[py].insert(*r[vy].rbegin());
            }
            tot-=b[vx]+b[vy];
            swap(a[vx], a[vy]);
            swap(rev[x], rev[y]);
            b[vx] = (*r[vx].begin() == a[vx] && *r[vx].rbegin() == a[vx]+sz[vx]-1);
            b[vy] = (*r[vy].begin() == a[vy] && *r[vy].rbegin() == a[vy]+sz[vy]-1);
            tot+=b[vx]+b[vy];
            // cout << "b: " << endl;
            // for (int i = 1; i <= N; i++) {
            //     cout << b[i] << " ";
            // }
            // cout << endl;
            // cout << "tot2: " << tot << endl;
            if (px!=0) {
                tot-=b[px];
                b[px] = (*r[px].begin() == a[px] && *r[px].rbegin() == a[px]+sz[px]-1);
                tot+=b[px];
            }
            if (py!=0&&py!=px) {
                tot-=b[py];
                b[py] = (*r[py].begin() == a[py] && *r[py].rbegin() == a[py]+sz[py]-1);
                tot+=b[py];
            }
            // cout << "b: " << endl;
            // for (int i = 1; i <= N; i++) {
            //     cout << b[i] << " ";
            // }
            // cout << endl;
            // cout << "tot: " << tot << endl;
            cout << (tot==N?"YES":"NO") << endl;
        }
    }
    return 0;
}