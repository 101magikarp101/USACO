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

struct state {
    int x, y, t;
};

int M, X, Y, K;
bool vis[101][101];

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    memset(vis, false, sizeof(vis));
    cin >> X >> Y >> K >> M;
    int ans = INT_MAX;
    queue<state> q;
    q.push({0, 0, 0});
    while (!q.empty()) {
        state cur = q.front();
        q.pop();
        if (cur.t > K) continue;
        ans = min(ans, abs(M-cur.x-cur.y));
        if (!vis[0][cur.y]) {
            vis[0][cur.y] = true;
            q.push({0, cur.y, cur.t+1});
        }
        if (!vis[cur.x][0]) {
            vis[cur.x][0] = true;
            q.push({cur.x, 0, cur.t+1});
        }
        if (!vis[X][cur.y]) {
            vis[X][cur.y] = true;
            q.push({X, cur.y, cur.t+1});
        }
        if (!vis[cur.x][Y]) {
            vis[cur.x][Y] = true;
            q.push({cur.x, Y, cur.t+1});
        }
        int res = min(cur.x, Y-cur.y);
        if (!vis[cur.x-res][cur.y+res]) {
            vis[cur.x-res][cur.y+res] = true;
            q.push({cur.x-res, cur.y+res, cur.t+1});
        }
        res = min(X-cur.x, cur.y);
        if (!vis[cur.x+res][cur.y-res]) {
            vis[cur.x+res][cur.y-res] = true;
            q.push({cur.x+res, cur.y-res, cur.t+1});
        }
    }
    cout << ans << endl;
}