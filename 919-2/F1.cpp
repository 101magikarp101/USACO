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

struct state {
    int x, y;
    int d;
};

int N, M, Q;
vt<vt<char>> a;
vt<vt<int>> dist;
vt<vt<int>> vis;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dx1[] = {1,1,1,0,0,-1,-1,-1};
int dy1[] = {1,0,-1,1,-1,1,0,-1};

bool good(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

bool check(int x, int y, int d) {
    if (dist[x][y] < d) return false;
    for (int i = 0; i < N; i++) {
        fill(vis[i].begin(), vis[i].end(), false);
    }
    queue<pii> q;
    q.push({x, y});
    while (!q.empty()) {
        pii p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = p.first+dx[i];
            int ny = p.second+dy[i];
            if (good(nx, ny) && a[nx][ny] != '#' && !vis[nx][ny] && dist[nx][ny] >= d) {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M;j++) {
            if (a[i][j] == '#') {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        pii p = q.front();
        q.pop();
        if (p.first == 0 || p.first == N-1 || p.second == 0 || p.second == M-1) return false;
        for (int i = 0; i < 8; i++) {
            int nx = p.first+dx1[i];
            int ny = p.second+dy1[i];
            if (good(nx, ny) && !vis[nx][ny]) {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
    return true;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> Q;
    a = vt<vt<char>>(N, vt<char>(M));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            a[i][j] = s[j];
        }
    }
    dist = vt<vt<int>>(N, vt<int>(M, INT_MAX));
    vis = vt<vt<int>>(N, vt<int>(M, false));
    queue<state> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){
            if (a[i][j] == 'v') {
                q.push({i, j, 0});
            }
        }
    }
    while (!q.empty()) {
        state s = q.front();
        q.pop();
        if (dist[s.x][s.y] != INT_MAX) continue;
        dist[s.x][s.y] = s.d;
        for (int i = 0; i < 4; i++) {
            int nx = s.x+dx[i];
            int ny = s.y+dy[i];
            if (good(nx, ny)) {
                q.push({nx, ny, s.d+1});
            }
        }
    }
    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        int low = 0, high = N+M+5;
        while (low < high) {
            int mid = (low+high+1)/2;
            if (check(x, y, mid)) {
                low = mid;
            } else {
                high = mid-1;
            }
        }
        cout << low << '\n';
    }
}