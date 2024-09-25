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
    int x, y;
    point(int x, int y) : x(x), y(y) {}
    point() {}
};

struct node {
    point p;
    vt<int> c;
    ll res[4];
    node(point p) {
        this->p = p;
        for (int i = 0; i < 4; i++) {
            res[i] = 0;
        }
    }
};

int T, N, M;
char a[1000][1000];
int idx[1000][1000];
bool vis[1000][1000];
vt<node> o;

vt<point> dx[4] = {{{-1,0},{0,1}},{{1,0},{0,1}},{{1,0},{0,-1}},{{-1,0},{0,-1}}};
// point rad[12] = {{-1,0},{0,1},{1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1},{-2,0},{0,2},{2,0},{0,-2}};
point rad[4] = {{-1,0},{0,1},{1,0},{0,-1}};
bool inbound(int x, int y);
ll add(ll a, ll b) {
    return (a+b)%MOD2;
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

ll mult(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    ll res = binpow(a, b/2);
    if (b%2) return mult(mult(res, res), a);
    else return mult(res, res);
}

bool good(int x, int y, int dir, vt<point> p = {}) {
    for (int i = 0; i < 2; i++) {
        int nx = x+dx[dir][i].x, ny = y+dx[dir][i].y;
        if (!inbound(nx, ny)) return false;
        if (a[nx][ny] == '#' || a[nx][ny]=='o') return false;
        for (int j = 0; j < p.size(); j++) {
            if (nx == p[j].x && ny == p[j].y) return false;
        }
    }
    return true;
}

bool inbound(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

ll solve(int n) {
    ll ans = 1;
    vis[o[n].p.x][o[n].p.y] = true;
    bool done = true;
    // cout << "n: " << n << " x: " << o[n].p.x << " y: " << o[n].p.y << " res: ";
    // for (int i = 0; i < 4; i++) {
    //     cout << o[n].res[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < o[n].c.size(); i++) {
        int c = o[n].c[i];
        if (vis[o[c].p.x][o[c].p.y]) continue;
        done = false;
        for (int d1 = 0; d1 < 4; d1++) {
            if (!good(o[n].p.x, o[n].p.y, d1)) continue;
            vt<point> p = {o[n].p};
            for (int j = 0; j < 2; j++) {
                int nx = o[n].p.x+dx[d1][j].x, ny = o[n].p.y+dx[d1][j].y;
                p.push_back({nx, ny});
            }
            for (int d2 = 0; d2 < 4; d2++) {
                if (!good(o[c].p.x, o[c].p.y, d2, p)) continue;
                o[c].res[d2] = add(o[c].res[d2], o[n].res[d1]);
            }
        }
    }
    if (done) {
        ll res = 0;
        for (int i = 0; i < 4; i++) {
            res = add(res, o[n].res[i]);
            // cout << "i: " << i << " res: " << o[n].res[i] << endl;
        }
        // cout << "x: " << o[n].p.x << " y: " << o[n].p.y << " res: " << res << endl;
        return res;
    }
    for (int i = 0; i < o[n].c.size(); i++) {
        int c = o[n].c[i];
        if (vis[o[c].p.x][o[c].p.y]) continue;
        ans = mult(ans, solve(c));
    }
    // cout << "x: " << o[n].p.x << " y: " << o[n].p.y << " ans: " << ans << endl;
    return ans;
}

int main () {
    cin >> T;
    while (T--) {
        o.clear();
        cin >> N >> M;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < M; j++) {
                vis[i][j] = false;
                a[i][j] = s[j];
                if (a[i][j] == 'o') {
                    idx[i][j] = cnt++;
                    node n = node({i,j});
                    o.push_back(n);
                } else {
                    idx[i][j] = -1;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (a[i][j] != 'o') continue;
                for (int k = 0; k < 12; k++) {
                    int nx = i+rad[k].x, ny = j+rad[k].y;
                    if (inbound(nx, ny) && a[nx][ny] == 'o') {
                        o[idx[i][j]].c.push_back(idx[nx][ny]);
                    }
                }
            }
        }
        ll ans = 1;
        for (int i = 0; i < o.size(); i++) {
            // cout << "i: " << i << endl;
            if (vis[o[i].p.x][o[i].p.y]) continue;
            for (int j = 0; j < 4; j++) {
                if (!good(o[i].p.x, o[i].p.y, j)) continue;
                o[i].res[j] = 1;
            }
            ans = mult(ans, solve(i));
            // cout << "i: " << i << " ans: " << ans << endl;
        }
        cout << ans << endl;
    }
}