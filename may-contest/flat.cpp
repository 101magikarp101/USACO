#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N;
vt<int> adj[100005];
bool vis[100005];
int a[100005];

ll calc(int x) {
    if (x==1) {
        if (adj[x].size()<=0) {
            return 0;
        }
        int res = 0;
        for (int i : adj[x]) {
            if (!vis[i]) {
                vis[i] = 1;
                res += calc(i);
            }
        }
        // a[x] = res+adj[x].size()-2;
        return res+adj[x].size()-2;
    } else {
        if (adj[x].size()<=1) {
            return 0;
        }
        int res = 0;
        for (int i : adj[x]) {
            if (!vis[i]) {
                vis[i] = 1;
                res += calc(i);
            }
        }
        // a[x] = res+adj[x].size()-2;
        return res+adj[x].size()-2;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis[1] = 1;
    cout << calc(1) << "\n";
    // cout << "a: " << endl;
    // for (int i = 1; i <= N; i++) {
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    return 0;
}