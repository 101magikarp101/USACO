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
int ans[200005];

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

void solve (int n, int in) {
    if (vis[n]) return;
    vis[n] = true;
    ans[n] = in;
    vector<pii> v;
    for (int i : adj[n]) {
        if (!vis[i]) {
            v.push_back({dist[i], i});
        }
    }
    if (v.size() == 0) {
        return;
    } else {
        sort(v.begin(), v.end(), greater<pii>());
        ans[n] = max(ans[n], v[0].first);
        for (int i = 0; i < v.size(); i++) {
            if (i == 0) {
                solve(v[i].second, v.size()>1 ? max(v[i+1].first, in)+1 : in+1);
            } else {
                solve(v[i].second, max(v[0].first, in)+1);
            }
        }
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
    solve(1, 0);
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
}