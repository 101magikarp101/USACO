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
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
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

int N, M, S, T;
int a[25][25];
int sum = 0;

int check(int x, int y, vt<vt<bool>> &v) {
    if (sz(v)+x-1 >= N || sz(v[0])+y-1 >= M) return 0;
    int res = 0;
    rep(i,0,sz(v)) {
        rep(j,0,sz(v[0])) {
            if (v[i][j]) {
                res += a[i+x][j+y];
            }
        }
    }
    return sum-res;
}

vt<vt<bool>> rot(vt<vt<bool>> &v) {
    vt<vt<bool>> res(sz(v[0]), vt<bool>(sz(v)));
    rep(i,0,sz(v)) {
        rep(j,0,sz(v[0])) {
            res[j][sz(v)-1-i] = v[i][j];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    rep(i,0,N) {
        rep(j,0,M) {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
    cin >> S >> T;
    vt<vt<bool>> v(S, vt<bool>(T));
    rep(i,0,S) {
        string s; cin >> s;
        rep(j,0,T) {
            v[i][j] = s[j] == '#';
        }
    }
    int ans = 0;
    rep(d,0,4) {
        rep(i,0,N) {
            rep(j,0,M) {
                ckmax(ans, check(i,j,v));
            }
        }
        v = rot(v);
    }
    cout << ans << endl;
    return 0;
}