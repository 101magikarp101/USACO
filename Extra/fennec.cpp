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

using namespace std;

int N;
vector<int> a[100005];
bool vis[100005];
int color[100005];

vector<int> find_route(int start, int end) {
    queue<pair<int, vector<int>>> q;
    q.push({start, {start}});
    while (!q.empty()) {
        pair<int, vector<int>> cur = q.front(); q.pop();
        vis[cur.first] = true;
        if (cur.first == end) return cur.second;
        for (int i = 0; i < a[cur.first].size(); i++) {
            if (!vis[a[cur.first][i]]) {
                vector<int> new_path = cur.second;
                new_path.push_back(a[cur.first][i]);
                q.push({a[cur.first][i], new_path});
            }
        }
    }
}

int fill(int node, int c) {
    color[node] = c;
    vis[node] = true;
    int ans = 1;
    for (int i = 0; i < a[node].size(); i++) {
        if (!vis[a[node][i]] && color[a[node][i]] != 1-c) {
            ans += fill(a[node][i], c);
        }
    }
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    vector<int> v = find_route(1, N);
    memset(vis, false, sizeof(vis));
    memset(color, -1, sizeof(color));
    for (int i = (v.size()+1)/2; i < v.size(); i++) {
        color[v[i]] = 1;
    }
    int black = fill(1, 0);
    int white = N-black;
    if (black > white) {
        cout << "Fennec" << endl;
    } else {
        cout << "Snuke" << endl;
    }
}