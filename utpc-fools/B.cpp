#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

struct state {
    int x, y, d;
};

int T, N, M;
char a[101][101];
bool vis[101][101];

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

bool good (int x, int y) {
    return a[x][y] != '#' && !vis[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int sx, sy, ex, ey;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'P') {
                sx = i;
                sy = j;
            }
            if (a[i][j] == 'O') {
                ex = i;
                ey = j;
            }
        }
    }
    queue<state> q;
    q.push({sx, sy, 0});
    while (!q.empty()) {
        state u = q.front();
        q.pop();
        if (u.x == ex && u.y == ey) {
            cout << u.d << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int x = u.x + dx[i];
            int y = u.y + dy[i];
            if (x == -1) x = N-1;
            if (x == N) x = 0;
            if (y == -1) y = M-1;
            if (y == M) y = 0;
            if (good(x, y)) {
                vis[x][y] = 1;
                q.push({x, y, u.d+1});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}