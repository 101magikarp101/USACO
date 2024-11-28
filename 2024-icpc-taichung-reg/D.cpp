#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)((x).size())
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define each(i,a) for(auto &i:a)
struct pii {
    int x, y;
    bool operator<(const pii &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pii &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pii &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pii &a) const { return x != a.x || y != a.y; }
    pii operator+(const pii &a) const { return {x+a.x, y+a.y}; }
    pii operator-(const pii &a) const { return {x-a.x, y-a.y}; }
    pii operator*(const int &a) const { return {x*a, y*a}; }
    pii operator/(const int &a) const { return {x/a, y/a}; }
};
struct pll {
    ll x, y;
    bool operator<(const pll &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pll &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pll &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pll &a) const { return x != a.x || y != a.y; }
    pll operator+(const pll &a) const { return {x+a.x, y+a.y}; }
    pll operator-(const pll &a) const { return {x-a.x, y-a.y}; }
    pll operator*(const ll &a) const { return {x*a, y*a}; }
    pll operator/(const ll &a) const { return {x/a, y/a}; }
};

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

int N, M;
char a[10005][10005];
int sx, sy, ex, ey;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool in(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

struct state {
    int x, y, dis, dir, cnt;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    vt<vt<vt<vt<bool>>>> vis(N, vt<vt<vt<bool>>>(M, vt<vt<bool>>(4, vt<bool>(4))));
    rep(i,0,N) {
        rep(j,0,M) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (a[i][j] == 'T') {
                ex = i;
                ey = j;
            }
        }
    }
    queue<state> q;
    rep(d,0,4) {
        int x = sx+dx[d], y = sy+dy[d];
        if (in(x, y) && a[x][y] != '#') {
            q.push({x, y, 1, d, 1});
            vis[x][y][d][1] = 1;
        }
    }
    while (!q.empty()) {
        state cur = q.front();
        // cout << cur.x << " " << cur.y << " " << cur.dis << " " << cur.dir << " " << cur.cnt << endl;
        q.pop();
        if (cur.x == ex && cur.y == ey) {
            cout << cur.dis << endl;
            return 0;
        }
        rep(d,0,4) {
            int x = cur.x+dx[d], y = cur.y+dy[d];
            if (in(x, y) && a[x][y] != '#') {
                if (d == cur.dir && cur.cnt < 3) {
                    if (vis[x][y][d][cur.cnt+1]) {
                        continue;
                    }
                    vis[x][y][d][cur.cnt+1] = 1;
                    q.push({x, y, cur.dis+1, d, cur.cnt+1});
                } else if (d != cur.dir) {
                    if (vis[x][y][d][1]) {
                        continue;
                    }
                    vis[x][y][d][1] = 1;
                    q.push({x, y, cur.dis+1, d, 1});
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}