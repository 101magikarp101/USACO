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

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct path {
    int d;
    string s;
};

struct state {
    int x, y, d, m;
    string s;
};

int N, M;
char grid[10][10];
path dp[10][10][(1<<10)-1];
int sx, sy, ex, ey;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool good(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < M;
}

int main () {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            grid[i][j] = s[j];
            if (s[j] == 'S') {
                sx = i;
                sy = j;
            } else if (s[j] == 'X') {
                ex = i;
                ey = j;
            }
            for (int k = 0; k < (1<<10); k++) {
                dp[i][j][k] = {INT_MAX, ""};
            }
        }
    }
    queue<state> q;
    q.push({sx, sy, 0, 0, "S"});
    while (!q.empty()) {
        state cur = q.front();
        q.pop();
        if (cur.x == ex && cur.y == ey) {
            cout << cur.s << endl;
            return 0;
        }
        if (dp[cur.x][cur.y][cur.m].d <= cur.d) {
            continue;
        }
        dp[cur.x][cur.y][cur.m] = {cur.d, cur.s};
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (!good(nx, ny)) {
                continue;
            }
            if (grid[nx][ny] == '#') {
                continue;
            }
            if (grid[nx][ny]>='A'&&grid[nx][ny]<='J') {
                if (!(cur.m & (1<<(grid[nx][ny]-'A')))) {
                    continue;
                }
            }
            int nm = cur.m;
            string ns = cur.s;
            if (grid[nx][ny]>='a'&&grid[nx][ny]<='j') {
                nm |= (1<<(grid[nx][ny]-'a'));
            }
            if (grid[nx][ny]!='.') {
                ns+=' ';
                ns+=grid[nx][ny];
            }
            q.push({nx, ny, cur.d+1, nm, ns});
        }
    }
}