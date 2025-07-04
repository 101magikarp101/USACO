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

int N;
vector<set<int>> adj;
bool visited[201];
struct cow {
    int x, y, r;
} cows[201];

int dfs(int node) {
    visited[node] = true;
    int ret = 1;
    for (int i : adj[node]) {
        if (!visited[i]) {
            ret += dfs(i);
        }
    }
    return ret;
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> N;
    adj = vector<set<int>>(N + 1);
    for (int i = 1; i <= N; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        cows[i] = {x, y, r};
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            int dx = cows[i].x - cows[j].x;
            int dy = cows[i].y - cows[j].y;
            int dist = dx * dx + dy * dy;
            if (dist <= cows[i].r * cows[i].r) {
                adj[i].insert(j);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        int res = dfs(i);
        if (res > ans) ans = res;
    }
    cout << ans << endl;
}