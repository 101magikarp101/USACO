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
vector<int> adj[100001];
bool visited[100001];
int color[100001];

int main() {
    memset(visited, false, sizeof(visited));
    memset(color, 0, sizeof(color));
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            color[i] = 1;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int j = 0; j < adj[node].size(); j++) {
                    if (color[adj[node][j]] == color[node]) {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    } else if (!visited[adj[node][j]]) {
                        visited[adj[node][j]] = true;
                        color[adj[node][j]] = 3 - color[node];
                        q.push(adj[node][j]);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << color[i] << " ";
    }
}