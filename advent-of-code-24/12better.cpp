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
bool vis[145][145];
bool vis2[145][145];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool in(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int solve2(int x, int y) {
    queue<pii> q;
    q.push({x, y});
    int peri = 0;
    while (!q.empty()) {
        pii p = q.front();
        q.pop();
        if (vis2[p.x][p.y]) continue;
        vis2[p.x][p.y] = 1;
        bool used = 0;
        vt<bool> hm(4,0);
        rep(i,0,4) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if (!in(nx, ny) || a[nx][ny] != a[x][y]) {
                hm[i] = 1;
            } else if (!vis2[nx][ny] && in(nx, ny)) {
                q.push({nx, ny});
            }
        }
        rep(i,0,4) {
            if (hm[i] && hm[(i+1)%4]) {
                peri++;
            }
        }
    }
    return peri;
}

int solve(int x, int y) {
    queue<pii> q;
    q.push({x, y});
    int area = 0;
    while (!q.empty()) {
        pii p = q.front();
        q.pop();
        if (vis[p.x][p.y]) continue;
        area++;
        vis[p.x][p.y] = 1;
        rep(i,0,4) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if (in(nx, ny) && a[nx][ny] == a[x][y]) {
                q.push({nx, ny});
            }
        }
    }
    int peri = solve2(x,y);
    // cout << "char: " << a[x][y] << endl;
    // cout << "a: " << area << " p: " << peri << endl;
    return area*peri;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto start = chrono::high_resolution_clock::now();
    // N = 10;
    N = 140;
    rep(i,0,N) {
        rep(j,0,N) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    rep(i,0,N) {
        rep(j,0,N) {
            if (!vis[i][j]) {
                ans += solve(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}