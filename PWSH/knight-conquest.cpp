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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct point {
    ll x, y;
};

struct state {
    point p;
    ll d;
};

ll N, M;
char a[5005][5005];
int vis[5005][5005];

bool good(ll x, ll y) {
    return 1<=x&&x<=N&&1<=y&&y<=M;
}

point operator+(point a, point b) {
    return {a.x+b.x, a.y+b.y};
}

point dx[8] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

int main () {
    cin >> N >> M;
    int sx=-1, sy=-1, ex=-1, ey=-1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            vis[i][j] = INT_MAX;
            cin >> a[i][j];
            if (a[i][j] == 'H') {
                sx = i;
                sy = j;
            }
            if (a[i][j] == 'J') {
                ex = i;
                ey = j;
            }
        }
    }
    queue<state> q;
    q.push({{sx, sy}, 0});
    while (!q.empty()) {
        state s = q.front();
        q.pop();
        if (s.p.x == ex && s.p.y == ey) {
            cout << s.d << endl;
            return 0;
        }
        if (vis[s.p.x][s.p.y] <= s.d) {
            continue;
        }
        vis[s.p.x][s.p.y] = s.d;
        for (int i = 0; i < 8; i++) {
            point np = s.p+dx[i];
            if (good(np.x, np.y) && a[np.x][np.y] != 'X') {
                q.push({np, s.d+1});
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}