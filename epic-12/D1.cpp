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
vt<int> adj[100005];
int id[100005], idrev[100005];
int a[100005], b[100005];
int d[100005];
int t;

void dfs(int u, int p, int depth) {
    d[t] = depth;
    id[u] = t;
    idrev[t] = u;
    for (int v : adj[u]) {
        if (v==p) continue;
        t++;
        dfs(v, u, depth/2);
    }
}

bool checkp(int x) {
    if (d[x]==1) return 1;
    else return a[x]==a[x+1]/2 && a[x]==a[x+d[x]]/2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
            d[i] = 0;
        }
        for (int i = 2; i <= N; i++) {
            int x; cin >> x;
            adj[x].push_back(i);
        }
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        t = 1;
        dfs(1, 0, (N+1)/2);
        // cout << "d: ";
        // for (int i = 1; i <= N; i++) {
        //     cout << d[i] << " ";
        // }
        // cout << endl;
        int tot = 0;
        for (int i = 1; i <= N; i++) {
            b[i] = checkp(i);
            tot+=b[i];
        }
        while (Q--) {
            int x, y; cin >> x >> y;
            tot-=b[x];
            tot-=b[y];
            swap(a[x], a[y]);
            b[x] = checkp(x);
            b[y] = checkp(y);
            tot+=b[x];
            tot+=b[y];
            int xp = idrev[x]/2, yp = idrev[y]/2;
            if (xp > 0) {
                xp = id[xp];
                tot-=b[xp];
                b[xp] = checkp(xp);
                tot+=b[xp];
            }
            if (yp > 0) {
                yp = id[yp];
                tot-=b[yp];
                b[yp] = checkp(yp);
                tot+=b[yp];
            }
            // cout << "tot: " << tot << endl;
            // cout << "b: ";
            // for (int i = 1; i <= N; i++) {
            //     cout << b[i] << " ";
            // }
            // cout << endl;
            cout << (tot==N ? "YES" : "NO") << endl;
        }
    }
    return 0;
}