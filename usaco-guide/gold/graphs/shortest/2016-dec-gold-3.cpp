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
};

int dx[] = {0, 1};
int dy[] = {1, 0};

int N, sx, sy, ex, ey;
vt<vt<bool>> grid;
pii a[100005];
vt<bool> vx, vy;

bool good (int x, int y) {
    return x>=0 && x<N && y>=0 && y<N;
}

int main() {
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    cin >> N >> sx >> sy >> ex >> ey;
    set<int> xs, ys;
    map<int, int> xm, ym;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
        xs.insert(x);
        ys.insert(y);
    }
    xs.insert(sx);
    xs.insert(ex);
    ys.insert(sy);
    ys.insert(ey);
    int cnt = 0;
    for (int i: xs) {
        xm[i] = cnt++;
    }
    cnt = 0;
    for (int i: ys) {
        ym[i] = cnt++;
    }
    vx = vt<bool>(xs.size(), 0);
    vy = vt<bool>(ys.size(), 0);
    grid = vt<vt<bool>>(xs.size(), vt<bool>(ys.size(), 0));
    for (int i = 0; i < N; i++) {
        grid[xm[a[i].x]][ym[a[i].y]] = 1;
    }
    // cout << "grid" << endl;
    // for (int i = 0; i < xs.size(); i++) {
    //     for (int j = 0; j < ys.size(); j++) {
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }
    sx = xm[sx];
    sy = ym[sy];
    ex = xm[ex];
    ey = ym[ey];
    // cout << "sx: " << sx << " sy: " << sy << " ex: " << ex << " ey: " << ey << endl;
    queue<state> q;
    q.push({sx, sy, 0, 0});
    q.push({sx, sy, 0, 1});
    while (q.size()) {
        state u = q.front();
        q.pop();
        // cout << "u: u.x: " << u.x << " u.y: " << u.y << " u.d: " << u.d << " u.dir: " << u.dir << endl;
        if (u.dir == 0) {
            vx[u.x] = 1;
        } else {
            vy[u.y] = 1;
        }
        int cnt = 1;
        while (true) {
            int nx = u.x+dx[u.dir]*cnt;
            int ny = u.y+dy[u.dir]*cnt;
            if (nx==ex && ny==ey) {
                cout << u.d << endl;
                return 0;
            }
            cnt++;
            if (!good(nx,ny)) break;
            if (grid[nx][ny]) {
                q.push({nx, ny, u.d+1, (u.dir+1)%2});
            }
        }
        cnt = -1;
        while (true) {
            int nx = u.x+dx[u.dir]*cnt;
            int ny = u.y+dy[u.dir]*cnt;
            if (nx==ex && ny==ey) {
                cout << u.d << endl;
                return 0;
            }
            cnt--;
            if (!good(nx,ny)) break;
            if (grid[nx][ny]) {
                q.push({nx, ny, u.d+1, (u.dir+1)%2});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}