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
vector<vector<int>> adj;
bool visited[501];

bool dfs(int node, int target) {
    visited[node] = true;
    for (int i : adj[node]) {
        if (i == target) {
            return true;
        }
        if (!visited[i]) {
            bool res = dfs(i, target);
            if (res) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> N;
    adj = vector<vector<int>>(N+1);
    for (int i = 1; i <= N; i++) {
        bool flag = true;
        for (int j = 1; j <= N; j++) {
            int x;
            cin >> x;
            if (x == i) {
                flag = false;
            }
            if (flag) {
                adj[i].push_back(x);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        bool flag = true;
        memset(visited, false, sizeof(visited));
        for (int j : adj[i]) {
            bool res = dfs(j, i);
            if (res) {
                cout << j << endl;
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << i << endl;
        }
    }
}