#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>

#define ll long long

using namespace std;

int N, M;
vector<int> adj[100001];
bool visited[100001];

void dfs(int node) {
    //cout << "node: " << node << endl;
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {
        if (!visited[adj[node][i]]) {
            dfs(adj[node][i]);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> nodes;
    for (int i = 1; i <= N; i++) {
        //cout << "i: " << i << endl;
        if (!visited[i]) {
            dfs(i);
            nodes.push_back(i);
        }
    }
    cout << nodes.size() - 1 << endl;
    for (int i = 0; i < nodes.size() - 1; i++) {
        cout << nodes[i] << " " << nodes[i + 1] << endl;
    }
}