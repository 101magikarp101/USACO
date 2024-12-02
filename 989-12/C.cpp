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

int T, N, M;
char a[1005][1005];
int b[1005][1005];
bool vis[1005][1005];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
map<char,int> dir = {{'R',0},{'L',1},{'D',2},{'U',3}};

bool in(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int solve(int x, int y) {
    if (vis[x][y] && b[x][y] == 0) {
        b[x][y] = 1;
        return 1;
    }
    if (vis[x][y]) {
        return b[x][y];
    }
    vis[x][y] = 1;
    int nx = x + dx[dir[a[x][y]]];
    int ny = y + dy[dir[a[x][y]]];
    if (!in(nx,ny)) {
        b[x][y] = -1;
        return -1;
    }
    if (a[nx][ny] == '?') {
        b[x][y] = 1;
        return 1;
    }
    b[x][y] = solve(nx,ny);
    return b[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        rep(i,0,N) {
            rep(j,0,M) {
                cin >> a[i][j];
                b[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        rep(i,0,N) {
            rep(j,0,M) {
                if (b[i][j] == 0 && a[i][j] != '?') {
                    solve(i, j);
                }
            }
        }
        // cout << "b:" << endl;
        // rep(i,0,N) {
        //     rep(j,0,M) {
        //         cout << b[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int ans = 0;
        rep(i,0,N) {
            rep(j,0,M) {
                if (b[i][j] == 1) {
                    ans++;
                } else if (b[i][j] == 0 && a[i][j] == '?') {
                    rep(d,0,4) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if (in(nx,ny) && (b[nx][ny] == 1 || a[nx][ny] == '?')) {
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}