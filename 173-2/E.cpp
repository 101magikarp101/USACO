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

int T, N, M;

struct state {
    bool r; int x;
};

int solve(vt<vt<int>> &a, vt<vt<int>> &b) {
    rep(k,0,N*M) {
        rep(j,0,M) {
            int m = 0;
            rep(i,0,N) {
                m |= b[i][j]&(~a[i][j]);
            }
            rep(i,0,N) {
                a[i][j] |= m;
            }
        }
        rep(i,0,N) {
            int m = 0;
            rep(j,0,M) {
                m |= a[i][j]&(~b[i][j]);
            }
            rep(j,0,M) {
                a[i][j] &= ~m;
            }
        }
    }
    rep(i,0,N) {
        rep(j,0,M) {
            if (a[i][j] != b[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        vt<vt<int>> a(N, vt<int>(M));
        vt<vt<int>> b(N, vt<int>(M));
        rep(i,0,N) {
            rep(j,0,M) {
                cin >> a[i][j];
            }
        }
        rep(i,0,N) {
            rep(j,0,M) {
                cin >> b[i][j];
            }
        }
        int ans = solve(a,b);
        cout << (ans?"YES":"NO") << endl;
    }
    return 0;
}