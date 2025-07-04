#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>

#define ll long long

using namespace std;

int N, M;
vector<set<int>> adj;
bool visited[100001];
struct cow {
    int x, y;
} cows[100001];

vector<int> dfs(int node, int left, int right, int top, int bottom) {
    visited[node] = true;
    vector<int> ret = {1, left, right, top, bottom};
    for (int i : adj[node]) {
        if (!visited[i]) {
            auto vec = dfs(i, cows[i].x, cows[i].x, cows[i].y, cows[i].y);
            ret[0] += vec[0];
            ret[1] = min(ret[1], vec[1]);
            ret[2] = max(ret[2], vec[2]);
            ret[3] = min(ret[3], vec[3]);
            ret[4] = max(ret[4], vec[4]);
        }
    }
    // cout << "node: " << node << endl;
    // cout << "vector: " << ret[0] << " " << ret[1] << " " << ret[2] << " " << ret[3] << " " << ret[4] << endl;
    return ret;
}

int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    cin >> N >> M;
    memset(visited, false, sizeof(visited));
    adj = vector<set<int>>(N + 1);
    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        cows[i] = {x, y};
    }
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    int ans = 2147483647;
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        int left = cows[i].x, right = cows[i].x, top = cows[i].y, bottom = cows[i].y;
        auto vec = dfs(i, left, right, top, bottom);
        //cout << "results: " << vec[0] << " " << vec[1] << " " << vec[2] << " " << vec[3] << " " << vec[4] << endl;
        int peri = 2 * (vec[2] - vec[1] + vec[4] - vec[3]);
        if (peri < ans) ans = peri;
    }
    cout << ans << endl;
}