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
#define rrep(i,a,b) for(int i=a;i>=b;i--)
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

int T, N;
char a[145][145];
int dist[145][145];
int sx, sy, ex, ey;
int tim;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int cx[] = {0,1,2,1,0,-1,-2,-1};
int cy[] = {2,1,0,-1,-2,-1,0,1};

bool in(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void solve1(int x, int y) {
    rep(i,0,N) {
        rep(j,0,N) {
            dist[i][j] = 1e9;
        }
    }
    dist[x][y] = 0;
    queue<pii> q;
    q.push({x, y});
    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        rep(i,0,4) {
            int nx = u.x + dx[i];
            int ny = u.y + dy[i];
            if (a[nx][ny] != '#' && dist[nx][ny] > dist[u.x][u.y] + 1) {
                dist[nx][ny] = dist[u.x][u.y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int solve() {
    int d[145][145];
    rep(i,0,N) {
        rep(j,0,N) {
            d[i][j] = 1e9;
        }
    }
    ll ans = 0;
    d[sx][sy] = 0;
    queue<pii> q;
    q.push({sx, sy});
    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        rep(i,0,4) {
            int nx = u.x + dx[i];
            int ny = u.y + dy[i];
            if (a[nx][ny] != '#' && d[nx][ny] > d[u.x][u.y] + 1) {
                d[nx][ny] = d[u.x][u.y] + 1;
                q.push({nx, ny});
            }
        }
        rep(di,-20,21) {
            rep(dj,-20,21) {
                int dis = abs(di) + abs(dj);
                if (dis > 20) continue;
                int nx = u.x + di;
                int ny = u.y + dj;
                if (!in(nx, ny)) continue;
                if (a[nx][ny] != '#') {
                    int t = d[u.x][u.y] + dis + dist[nx][ny];
                    if (t >= 1e9) continue;
                    if (tim-t >= 100) {
                        ans++;
                    }
                }
            }
        }
        // rep(i,0,8) {
        //     int nx = u.x + cx[i];
        //     int ny = u.y + cy[i];
        //     if (!in(nx, ny)) continue;
        //     if (a[nx][ny] != '#') {
        //         // cout << "nx: " << nx << " ny: " << ny << endl;
        //         int t = d[u.x][u.y] + 2 + solve1(nx, ny);
        //         if (t >= 1e9) continue;
        //         // cout << "t: " << tim-t << endl;
        //         if (tim-t >= 100) {
        //             ans++;
        //         }
        //     }
        // }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // N = 15;
    N = 141;
    rep(i,0,N) {
        rep(j,0,N) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (a[i][j] == 'E') {
                ex = i;
                ey = j;
            }
        }
    }
    solve1(ex, ey);
    tim = dist[sx][sy];
    // cout << "tim: " << tim << endl;
    ll ans = solve();
    cout << ans << endl;
    return 0;
}