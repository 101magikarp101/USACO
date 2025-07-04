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
    int x, y, d;
    char c;
};

struct point {
    int px, py, d;
    char c;
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string dc = "RLDU";

int N, M;
char grid[1002][1002];
point fin[1002][1002];
int sx, sy, ex, ey;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            grid[i][j] = s[j];
            if (grid[i][j]=='A') {
                sx = i;
                sy = j;
            } else if (grid[i][j]=='B') {
                grid[i][j] = '.';
                ex = i;
                ey = j;
            }
        }
    }
    queue<state> q;
    q.push({sx, sy, 0, 'A'});
    while (!q.empty()) {
        state cur = q.front();
        q.pop();
        // cout << "cur: " << cur.x << " " << cur.y << " " << cur.d << endl;
        if (cur.x==ex && cur.y==ey) {
            cout << "YES" << endl;
            cout << cur.d << endl;
            string ans;
            while (cur.x!=sx || cur.y!=sy) {
                ans += fin[cur.x][cur.y].c;
                int nx = fin[cur.x][cur.y].px;
                int ny = fin[cur.x][cur.y].py;
                cur.x = nx;
                cur.y = ny;
            }
            reverse(ans.begin(), ans.end());
            cout << ans << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.x+dx[i];
            int ny = cur.y+dy[i];
            if (nx<0 || nx>=N || ny<0 || ny>=M || grid[nx][ny]=='#') continue;
            if (grid[nx][ny]=='.' && fin[nx][ny].d == 0) {
                fin[nx][ny] = {cur.x, cur.y, cur.d+1, dc[i]};
                q.push({nx, ny, cur.d+1, dc[i]});
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}