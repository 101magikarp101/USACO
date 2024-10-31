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

struct state {
    int x1, y1, d1, x2, y2, d2, dist;
    bool b1, b2;
};

int T, N;
char grid[21][21];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool good (int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && grid[x][y] != 'H';
}

int main() {
    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < N; j++) {
            grid[i][j] = s[j];
        }
    }
    set<state> q;
    set<state> next;
    q.insert({N-1, 0, 3, N-1, 0, 0, 0, 0, 0});
    int ans = -1;
    while (!q.empty()) {
        while (!q.empty()) {
            state cur = *q.begin();
            q.erase(q.begin());
            // cout << "cur: " << cur.x1 << " " << cur.y1 << " " << cur.d1 << " " << cur.x2 << " " << cur.y2 << " " << cur.d2 << " " << cur.dist << " " << cur.b1 << " " << cur.b2 << endl;
            if (cur.x1 == 0 && cur.y1 == N-1) {
                cur.b1 = 1;
            }
            if (cur.x2 == 0 && cur.y2 == N-1) {
                cur.b2 = 1;
            }
            if (cur.b1 && cur.b2) {
                ans = cur.dist;
                break;
            }
            for (int i = -1; i <= 1; i+=2) {
                int nd1 = (cur.d1 + i + 4) % 4;
                int nd2 = (cur.d2 + i + 4) % 4;
                next.insert({cur.x1, cur.y1, nd1, cur.x2, cur.y2, nd2, cur.dist+1, cur.b1, cur.b2});
            }
            int nx1 = cur.x1, ny1 = cur.y1, nx2 = cur.x2, ny2 = cur.y2;
            if (good(cur.x1 + dx[cur.d1], cur.y1 + dy[cur.d1])) {
                nx1 = cur.x1 + dx[cur.d1];
                ny1 = cur.y1 + dy[cur.d1];
            }
            if (good(cur.x2 + dx[cur.d2], cur.y2 + dy[cur.d2])) {
                nx2 = cur.x2 + dx[cur.d2];
                ny2 = cur.y2 + dy[cur.d2];
            }
            if (good(nx1, ny1) && good(nx2, ny2)) {
                next.insert({nx1, ny1, cur.d1, nx2, ny2, cur.d2, cur.dist+1, cur.b1, cur.b2});
            }
        }
        if (ans != -1) break;
        swap(q, next);
    }
    cout << ans << endl;
    return 0;
}