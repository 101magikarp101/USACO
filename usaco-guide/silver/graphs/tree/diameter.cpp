#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int N;
vector<int> adj[200005];
int dist[200005];
bool vis[200005];
int fin = -1;

int fill (int node) {
    if (vis[node]) return 0;
    vis[node] = true;
    int res = 0;
    for (int i : adj[node]) {
        res = max(res, fill(i));
    }
    res++;
    dist[node] = res;
    return res;
}

void solve (int n) {
    if (vis[n]) return;
    vis[n] = true;
    int ans = 0;
    vector<int> v = {};
    for (int i : adj[n]) {
        if (!vis[i]) {
            v.push_back(dist[i]);
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    if (v.size() == 0) {
        ans = 1;
    } else if (v.size() == 1) {
        ans = v[0];
    } else {
        ans = v[0] + v[1];
    }
    fin = max(fin, ans);
    for (int i : adj[n]) {
        solve(i);
    }
}

int main() {
    cin >> N;
    if (N==1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= N-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill(1);
    memset(vis, false, sizeof(vis));
    solve(1);
    cout << fin << endl;
}