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
int vis[145][145][4];
bool b[145][145];
int sx, sy, ex, ey;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct state {
    int x, y, dir, c;
    vt<pii> path;
    bool operator<(const state &a) const { return c > a.c; }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // N = 17;
    N = 141;
    rep(i, 0, N) {
        rep(j, 0, N) {
            cin >> a[i][j];
            if (a[i][j] == 'S') sx = i, sy = j;
            if (a[i][j] == 'E') ex = i, ey = j;
            rep(k, 0, 4) {
                vis[i][j][k] = INT_MAX;
            }
        }
    }
    priority_queue<state> pq;
    pq.push({sx, sy, 0, 0, {{sx, sy}}});
    bool found = 0;
    int best = -1;
    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();
        if (!found && cur.x == ex && cur.y == ey) {
            found = 1;
            best = cur.c;
        }
        if (found && cur.c == best && cur.x == ex && cur.y == ey) {
            for (auto i : cur.path) {
                b[i.x][i.y] = 1;
            }
            continue;
        } else if (found && cur.c > best) {
            continue;
        }
        if (cur.c > vis[cur.x][cur.y][cur.dir]) continue;
        vis[cur.x][cur.y][cur.dir] = cur.c;
        int nx = cur.x + dx[cur.dir];
        int ny = cur.y + dy[cur.dir];
        vt<pii> np = cur.path;
        np.pb({nx, ny});
        if (a[nx][ny] != '#') {
            pq.push({nx, ny, cur.dir, cur.c + 1, np});
        }
        nx = cur.x + dx[(cur.dir + 1) % 4];
        ny = cur.y + dy[(cur.dir + 1) % 4];
        np = cur.path;
        np.pb({nx, ny});
        if (a[nx][ny] != '#') pq.push({nx, ny, (cur.dir + 1) % 4, cur.c + 1001, np});
        nx = cur.x + dx[(cur.dir + 3) % 4];
        ny = cur.y + dy[(cur.dir + 3) % 4];
        np = cur.path;
        np.pb({nx, ny});
        if (a[nx][ny] != '#') pq.push({nx, ny, (cur.dir + 3) % 4, cur.c + 1001, np});
    }
    int ans = 0;
    rep(i, 0, N) {
        rep(j, 0, N) {
            if (b[i][j]) ans++;
            cout << (b[i][j] ? 'X' : '.');
        }
        cout << endl;
    }
    cout << ans << endl;
    return 0;
}