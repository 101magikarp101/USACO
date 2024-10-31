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
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 1000000007
#define INT_MAX 2147483647

using namespace std;

struct light {
    int x, y;
};

int N, M;
bool on[101][101];
bool vis[101][101];
vector<light> l[101][101];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0 , -1};

bool good(int i, int j) {
    return i >= 1 && i <= N && j >= 1 && j <= N;
}

bool check(int i, int j) {
    bool res = false;
    for (int k = 0; k < 4; k++) {
        int nx = i+dx[k];
        int ny = j+dy[k];
        if (!good(nx, ny)) continue;
        res |= vis[nx][ny];
    }
    return res;
}

int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    memset(on, false, sizeof(on));
    memset(vis, false, sizeof(vis));
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        l[a][b].push_back({c, d});
    }
    deque<pii> q;
    q.push_back({1, 1});
    vis[1][1] = true;
    on[1][1] = true;
    int ans = 1;
    while (!q.empty()) {
        pii cur = q.front();
        // cout << "cur: " << cur.first << " " << cur.second << endl;
        q.pop_front();
        int x = cur.first;
        int y = cur.second;
        for (light i : l[x][y]) {
            if (!on[i.x][i.y]) {
                on[i.x][i.y] = true;
                ans++;
            }
            if (!vis[i.x][i.y] && check(i.x, i.y)) {
                vis[i.x][i.y] = true;
                q.push_back({i.x, i.y});
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (!good(nx, ny)) continue;
            if (!vis[nx][ny] && on[nx][ny]) {
                vis[nx][ny] = true;
                q.push_back({nx, ny});
            }
        }
    }
    cout << ans << endl;
}