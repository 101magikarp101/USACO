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
#define BIG 1000000000000

using namespace std;

int T, N, M;
vector<int> adj[100001];
bool visited[100001];
int colors[100001];

void dfs(int node, int color) {
    visited[node] = true;
    colors[node] = color;
    for (int i : adj[node]) {
        if (!visited[i]) {
            dfs(i, color);
        }
    }
}

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        memset(visited, false, sizeof(visited));
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        map<ll, pair<ll, ll>> sections;
        dfs(1, -1);
        //if all nodes are connected, then the answer is 0
        if (visited[N]) {
            cout << 0 << endl;
            continue;
        }
        dfs(N, -2);
        // cout << "visited: ";
        // for (int i = 1; i <= N; i++) {
        //     cout << visited[i] << " ";
        // }
        // cout << endl;
        // cout << "colors: ";
        // for (int i = 1; i <= N; i++) {
        //     cout << colors[i] << " ";
        // }
        // cout << endl;

        ll color = 1;
        for (ll i = 1; i <= N; i++) {
            if (visited[i]) continue;
            dfs(i, color);
            color++;
        }

        // cout << "visited: ";
        // for (int i = 1; i <= N; i++) {
        //     cout << visited[i] << " ";
        // }
        // cout << endl;
        // cout << "colors: ";
        // for (int i = 1; i <= N; i++) {
        //     cout << colors[i] << " ";
        // }
        // cout << endl;
        ll cost = BIG;
        ll prev = 1; //index of previous field with color -1
        for (ll i = 1; i <= N; i++) {
            if (colors[i] == -1) {
                prev = i;
            } else if (colors[i] == -2) {
                cost = min(cost, (i-prev)*(i-prev));
            }
        }
        ll prev2 = -1; //index of previous field with color -1
        for (ll i = N; i >= 1; i--) {
            if (colors[i] == -1) {
                prev2 = i;
            } else if (prev2 != -1 && colors[i] == -2) {
                cost = min(cost, (prev2-i)*(prev2-i));
            }
        }
        // cout << "cost: " << cost << endl;
        if (color >= 2) {
            for (ll i = 1; i <= color; i++) {
                sections[i] = {BIG, BIG};
            }
            // cout << "sections: ";
            // for (auto i : sections) {
            //     cout << i.first << " " << i.second.first << " " << i.second.second << endl;
            // }
            ll prev = 1; //index of previous field with color -1
            for (ll i = 1; i <= N; i++) {
                if (colors[i] == -1) {
                    prev = i;
                } else if (colors[i] != -2) {
                    sections[colors[i]].first = min(sections[colors[i]].first, (i-prev)*(i-prev));
                }
            }
            prev = -1; //index of previous field with color -1
            for (ll i = N; i >= 1; i--) {
                if (colors[i] == -1) {
                    prev = i;
                } else if (prev != -1 && colors[i] != -2) {
                    sections[colors[i]].first = min(sections[colors[i]].first, (prev-i)*(prev-i));
                }
            }
            // cout << "sections: ";
            // for (auto i : sections) {
            //     cout << i.first << " " << i.second.first << " " << i.second.second << endl;
            // }
            ll prev2 = N; //index of previous field with color -2
            for (ll i = N; i >= 1; i--) {
                if (colors[i] == -2) {
                    prev2 = i;
                } else if (colors[i] != -1) {
                    sections[colors[i]].second = min(sections[colors[i]].second, (prev2-i)*(prev2-i));
                }
            }
            prev2 = -1; //index of previous field with color -2
            for (ll i = 1; i <= N; i++) {
                if (colors[i] == -2) {
                    prev2 = i;
                } else if (prev2 != -1 && colors[i] != -1) {
                    sections[colors[i]].second = min(sections[colors[i]].second, (i-prev2)*(i-prev2));
                }
            }
            // cout << "sections: ";
            // for (auto i : sections) {
            //     cout << i.first << " " << i.second.first << " " << i.second.second << endl;
            // }
            ll ans = BIG;
            for (auto i : sections) {
                ans = min(ans, i.second.first + i.second.second);
            }
            // cout << "ans: " << ans << endl;
            cost = min(cost, ans);
        }
        cout << cost << endl;
    }
}