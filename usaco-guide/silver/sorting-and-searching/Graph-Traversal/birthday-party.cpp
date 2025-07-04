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

int P, C;
struct edge {
    int to, id;
    bool operator<(const edge& other) const {
        return to < other.to;
    }
};
vector<set<edge>> adj;
bool visited[101];
int forbidden;

int dfs (int node) {
    visited[node] = true;
    int ret = 0;
    for (edge i : adj[node]) {
        if (i.id == forbidden) continue;
        if (!visited[i.to]) {
            ret += dfs(i.to);
        }
    }
    return ret + 1;
}

int main() {
    while (true) {
        cin >> P >> C;
        if (P == 0 && C == 0) break;
        adj = vector<set<edge>>(P);
        for (int i = 0; i < C; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].insert({b, i});
            adj[b].insert({a, i});
        }
        bool ans = true;
        for (int i = 0; i < C; i++) {
            forbidden = i;
            memset(visited, false, sizeof(visited));
            int res = dfs(0);
            if (res != P) {
                ans = false;
                break;
            }
        }
        if (!ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}