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

int N, K;
vector<set<int>> adj;
set<int> loopMembers;
bool visited[21];

void dfs(int node, vector<int> path) {
    visited[node] = true;
    path.push_back(node);
    for (int i : adj[node]) {
        if (!visited[i]) {
            dfs(i, path);
        } else {
            for (int j = path.size()-1; j >= 0; j--) {
                if (path[j] == i) {
                    for (int k = j; k < path.size(); k++) {
                        loopMembers.insert(path[k]);
                    }
                    break;
                }
            }
        }
    }
}

int main() {
    cin >> N >> K;
    adj = vector<set<int>>(N+1);
    for (int i = 0; i < K; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if (x > y) {
            adj[a].insert(b);
        } else {
            adj[b].insert(a);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        dfs(i, vector<int>());
    }
    cout << loopMembers.size() << endl;
}