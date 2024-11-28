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

int N, M;
vector<int> a[200005], b[200005];
bool v1[200005], v2[200005];
int deg1[200005], deg2[200005];

pii dist (vector<int> adj[], bool vis[], int n) {
    queue<pii> q;
    q.push({n, 0});
    vis[n] = true;
    pii ans = {n, 0};
    while (!q.empty()) {
        pii c = q.front();
        ans = c;
        q.pop();
        for (int i : adj[c.first]) {
            if (!vis[i]) {
                q.push({i, c.second+1});
                vis[i] = true;
            }
        }
    }
    return ans;
}

int diam (vector<int> adj[], bool vis[], int n, int ma) {
    for (int i = 1; i <= ma; i++) {
        vis[i] = false;
    }
    int f = dist(adj, vis, n).first;
    for (int i = 1; i <= ma; i++) {
        vis[i] = false;
    }
    int d = dist(adj, vis, f).second;
    return d;
}

int main() {
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
        deg1[x]++;
        deg1[y]++;
    }
    cin >> M;
    for (int i = 0; i < M-1; i++) {
        int x, y;
        cin >> x >> y;
        b[x].push_back(y);
        b[y].push_back(x);
        deg2[x]++;
        deg2[y]++;
    }
    int d1 = diam(a, v1, 1, N);
    int d2 = diam(b, v2, 1, M);
    int mid = (d1+1)/2 + (d2+1)/2 + 1;
    cout << max(d1, max(d2, mid)) << endl;
}