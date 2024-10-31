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
bool visited[3001];
bool removed[3001];

int dfs(int node)
{
    if (removed[node] || visited[node]) return 0;
    //cout << "node: " << node << endl;
    visited[node] = true;
    int ret = 1;
    for (int i : adj[node]) {
        if (!visited[i]) {
            ret += dfs(i);
        }
    }
    return ret;
}

int main()
{
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> N >> M;
    adj = vector<set<int>>(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    int query[3001];
    for (int i = 1; i <= N; i++) {
        cin >> query[i];
    }
    //cout << query[N] << endl;
    for (int i = 0; i < N; i++) {
        if (i != 0) {
            removed[query[i]] = true;
        }
        memset(visited, false, sizeof(visited));
        // cout << "removed: " << endl;
        // for (int j = 1; j <= N; j++) {
        //     cout << removed[j] << " ";
        // }
        // cout << endl;
        int res = dfs(query[N]);
        //cout << "res: " << res << endl;
        if (res == N - i) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}