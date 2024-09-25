#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

struct state{
    int x, y, d;
};

int N, M;
char a[1007][1007];
int dp[1007][1007];
int si = 0, sj = 0;
int ei = 0, ej = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool good(int x, int y) {
    return x >= 0 && x <= N+1 && y >= 0 && y <= M+1 && a[x][y] != '#';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i <= N+1; i++) {
        for (int j = 0; j <= M+1; j++) {
            a[i][j] = '.';
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                si = i;
                sj = j;
            }
            if (a[i][j] == 'E') {
                ei = i;
                ej = j;
            }
        }
    }
    for (int i = 0; i <= N+1; i++) {
        for (int j = 0; j <= M+1; j++) {
            dp[i][j] = 1e9;
        }
    }
    queue<state> q;
    q.push({si, sj, 0});
    dp[si][sj] = 0;
    while (!q.empty()) {
        state u = q.front();
        q.pop();
        if (u.x == ei && u.y == ej) {
            cout << u.d << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int ni = u.x+dx[i];
            int nj = u.y+dy[i];
            if (good(ni, nj) && dp[ni][nj] > u.d+1) {
                dp[ni][nj] = u.d+1;
                q.push({ni, nj, u.d+1});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}