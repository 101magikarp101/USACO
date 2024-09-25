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
#define BIG 1000000000000

using namespace std;

int T;
int N, M;
vector<int> adj[400010];
bool visited[400010];
int colorCount[2];
int colors[400010];
int tracker = 0;

void dfs(int node, int color) {
    visited[node] = true;
    colorCount[color]++;
    colors[node] = color;
    for (int i : adj[node]) {
        if (!visited[i]) {
            dfs(i, 1 - color);
        }
    }
    // cout << "node: " << node << " color: " << color << endl;
    // cout << "visited: ";
    // for (int i = 1; i <= N; i++) {
    //     cout << visited[i] << " ";
    // }
    // cout << endl;
    // cout << "colors[0]: ";
    // for (int i : colors[0]) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << "colors[1]: ";
    // for (int i : colors[1]) {
    //     cout << i << " ";
    // }
    // cout << endl;
}

int main() {
    cin >> T;
    string ans = "";
    for (int t = 0; t < T; t++) {
        memset(colorCount, 0, sizeof(colorCount));
        cin >> N >> M;
        for (int i = 1; i <= M; i++) {
            int a, b;
            cin >> a >> b;
            adj[tracker + a].push_back(tracker + b);
            adj[tracker + b].push_back(tracker + a);
        }
        dfs(tracker + 1, 0);
        // cout << "colors[0]: ";
        // for (int i : colors[0]) {
        //     cout << i << " ";
        // }
        // cout << endl;
        // cout << "colors[1]: ";
        // for (int i : colors[1]) {
        //     cout << i << " ";
        // }
        // cout << endl;
        if (colorCount[0] > colorCount[1]) {
            string a = "";
            a += to_string(colorCount[1]) + "\n";
            for (int i = tracker + 1; i <= tracker + N; i++) {
                if (colors[i] == 1) {
                    a += to_string(i - tracker) + " ";
                }
            }
            ans += a + "\n";
        } else {
            string a = "";
            a += to_string(colorCount[0]) + "\n";
            for (int i = tracker + 1; i <= tracker + N; i++) {
                if (colors[i] == 0) {
                    a += to_string(i - tracker) + " ";
                }
            }
            ans += a + "\n";
        }
        tracker += N;
    }
    cout << ans;
}