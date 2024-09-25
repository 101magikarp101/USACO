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
    int x, y, d, dir;
    bool o;
};

int N, M;
int grid[1003][1003];
int dp[1003][1003][2][4];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int good(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int main() {
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 4; l++) {
                    dp[i][j][k][l] = INT_MAX;
                }
            }
        }
    }
    queue<state> q;
    q.push({0, 0, 0, 0, 0});
    while (!q.empty()) {
        state s = q.front();
        q.pop();
        // cout << "s.x: " << s.x << " s.y: " << s.y << " s.d: " << s.d << " s.dir: " << s.dir << " s.o: " << s.o << endl;
        if (s.x == N-1 && s.y == M-1) {
            cout << s.d << endl;
            return 0;
        }
        if (dp[s.x][s.y][s.o][s.dir] <= s.d) continue;
        dp[s.x][s.y][s.o][s.dir] = s.d;
        if (grid[s.x][s.y] == 4) {
            int nx = s.x+dx[s.dir];
            int ny = s.y+dy[s.dir];
            if (good(nx, ny)) {
                if (grid[nx][ny] == 1) {
                    q.push({nx, ny, s.d+1, s.dir, s.o});
                    continue;
                } else if (grid[nx][ny] == 2) {
                    q.push({nx, ny, s.d+1, s.dir, 1});
                    continue;
                } else if (grid[nx][ny] == 3) {
                    if (s.o) {
                        q.push({nx, ny, s.d+1, s.dir, s.o});
                        continue;
                    }
                } else if (grid[nx][ny] == 4) {
                    q.push({nx, ny, s.d+1, s.dir, 0});
                    continue;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = s.x+dx[i];
            int ny = s.y+dy[i];
            if (good(nx, ny)) {
                if (grid[nx][ny] == 1) {
                    q.push({nx, ny, s.d+1, i, s.o});
                } else if (grid[nx][ny] == 2) {
                    q.push({nx, ny, s.d+1, i, 1});
                } else if (grid[nx][ny] == 3 && s.o) {
                    q.push({nx, ny, s.d+1, i, s.o});
                } else if (grid[nx][ny] == 4) {
                    q.push({nx, ny, s.d+1, i, 0});
                }
            }
        }
    }
    cout << -1 << endl;
}