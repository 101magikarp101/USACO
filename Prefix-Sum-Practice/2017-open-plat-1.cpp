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
#include <unordered_map>
#include <deque>
#include <climits>
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

struct rect {
    int x1, y1, x2, y2;
};

int N;
int a[1005][1005];
int pre[1005][1005];
bool vis[1005][1005];
bool vis1[1000005];
rect rects[1000005];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool good(int x, int y) {
    return x >= 1 && x <= N && y >= 1 && y <= N;
}

bool dfs2(int x, int y) {
    queue<pii> q;
    q.push({x, y});
    vis[x][y] = 1;
    bool ok = 1;
    while (!q.empty()) {
        pii cur = q.front();
        if (pre[cur.x][cur.y] != 1) {
            ok = 0;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (good(nx, ny) && !vis[nx][ny] && a[nx][ny] == a[x][y]) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    return ok;
}

int main() {
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    set<int> s;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
            vis[i][j] = 0;
            if (a[i][j] != 0) {
                s.insert(a[i][j]);
            }
        }
    }
    if (s.size() == 1) {
        cout << N*N-1 << endl;
        return 0;
    }
    for (int i = 1; i <= N*N; i++) {
        rects[i].x1 = INT_MAX;
        rects[i].y1 = INT_MAX;
        rects[i].x2 = INT_MIN;
        rects[i].y2 = INT_MIN;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (a[i][j]!=0) {
                rects[a[i][j]].x1 = min(rects[a[i][j]].x1, i);
                rects[a[i][j]].y1 = min(rects[a[i][j]].y1, j);
                rects[a[i][j]].x2 = max(rects[a[i][j]].x2, i);
                rects[a[i][j]].y2 = max(rects[a[i][j]].y2, j);
            }
        }
    }
    for (int i = 1; i <= N*N; i++) {
        if (rects[i].x1 != INT_MAX) {
            pre[rects[i].x1][rects[i].y1]++;
            pre[rects[i].x1][rects[i].y2+1]--;
            pre[rects[i].x2+1][rects[i].y1]--;
            pre[rects[i].x2+1][rects[i].y2+1]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    // cout << "pre: " << endl;
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << pre[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = N*N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (a[i][j]!=0 && !vis[i][j] && !vis1[a[i][j]] && !dfs2(i, j)) {
                // cout << a[i][j] << " " << i << " " << j << endl;
                vis1[a[i][j]] = 1;
                ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}