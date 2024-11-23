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

int N;
int dp[1<<19][19];
pii a[20];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    rep(i,0,N) cin >> a[i].x >> a[i].y;
    rep(i,0,1<<N) {
        rep(j,0,N) {
            dp[i][j] = INT_MAX;
        }
    }
    rep(m,1,1<<N) {
        rep(i,0,N) {
            if (m&(1<<i)) {
                int n = m^(1<<i);
                if (n == 0) {
                    dp[m][i] = 0;
                    continue;
                }
                rep(j,0,N) {
                    if (n&(1<<j)) {
                        int dx = a[i].x-a[j].x;
                        int dy = a[i].y-a[j].y;
                        ckmin(dp[m][i], max(dp[n][j], dx*dx+dy*dy));
                    }
                }
            }
        }
    }
    // rep(m,0,1<<N) {
    //     rep(i,0,N) {
    //         cout << dp[m][i] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = INT_MAX;
    rep(i,0,N) {
        ckmin(ans, dp[(1<<N)-1][i]);
    }
    if (N <= 2) {
        cout << N-1 << " ";
    } else {
        cout << 2 << " ";
    }
    cout << ans << endl;
    return 0;
}