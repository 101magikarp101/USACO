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

int N, M;
char a[1005][1005];
int dist[1005][1005];
int si, sj;
int ti, tj;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

bool valid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            a[i][j] = s[j];
            if (a[i][j] == 'S') {
                si = i;
                sj = j;
            } else if (a[i][j] == 'E') {
                ti = i;
                tj = j;
            }
        }
    }
    queue<state> q;
    q.push({si, sj, 0});
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dist[i][j] = INT_MAX;
        }
    }
    dist[si][sj] = 0;
    while (!q.empty()) {
        state u = q.front(); q.pop();
        if (u.x == ti && u.y == tj) {
            cout << u.d << endl;
            return 0;
        }
        for (int i = 0; i < 8; i++) {
            int nx = u.x + dx[i];
            int ny = u.y + dy[i];
            if (valid(nx, ny) && a[nx][ny] != '#' && dist[nx][ny] > u.d+1) {
                dist[nx][ny] = u.d+1;
                q.push({nx, ny, u.d+1});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}