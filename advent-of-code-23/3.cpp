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

ll T, N, M;
char a[1005][1005];
ll cnt[1005][1005];
ll tot[1005][1005];

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

bool in(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    N = 140;
    M = N;
    rep(i,0,N) {
        rep(j,0,M) {
            cin >> a[i][j];
            tot[i][j] = 1;
        }
    }
    ll ans = 0;
    rep(i,0,N) {
        ll res = 0;
        bool g = 0;
        set<pii> s;
        rep(j,0,M) {
            if ('0' <= a[i][j] && a[i][j] <= '9') {
                rep(d,0,8) {
                    int x = i+dx[d], y = j+dy[d];
                    if (in(x, y) && !('0' <= a[x][y] && a[x][y] <= '9') && a[x][y] != '.') {
                        s.insert({x, y});
                    }
                }
                res *= 10;
                res += a[i][j]-'0';
            } else {
                each(p,s) {
                    cnt[p.x][p.y]++;
                    tot[p.x][p.y] *= res;
                }
                s.clear();
                res = 0;
            }
        }
        each(p,s) {
            cnt[p.x][p.y]++;
            tot[p.x][p.y] *= res;
        }
    }
    rep(i,0,N) {
        rep(j,0,M) {
            if (cnt[i][j] == 2) {
                ans += tot[i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}