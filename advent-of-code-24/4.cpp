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
char a[1005][1005];
vt<vt<char>> tar = {
    {'M', ' ', 'S'},
    {' ', 'A', ' '},
    {'M', ' ', 'S'},
};

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

void rot() {
    vt<vt<char>> tmp = tar;
    rep(i,0,3) {
        rep(j,0,3) {
            tar[i][j] = tmp[2-j][i];
        }
    }
}

bool in(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool solve(int x, int y) {
    rep(i,0,3) {
        rep(j,0,3) {
            if (!in(x+i, y+j) || (a[x+i][y+j] != tar[i][j] && tar[i][j] != ' ')) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // N = 10;
    N = 140;
    rep(i,0,N) {
        rep(j,0,N) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    rep(d,0,4) {
        rep(i,0,N) {
            rep(j,0,N) {
                if (solve(i, j)) {
                    ans++;
                }
            }
        }
        rot();
    }
    cout << ans << endl;
    return 0;
}