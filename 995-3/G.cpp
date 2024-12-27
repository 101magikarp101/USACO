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

struct query {
    int i; char c;
};

int T, N, Q;
int a[25][25];
int dp[1<<20][21];
query q[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    rep(i,0,Q) {
        cin >> q[i].i >> q[i].c;
        q[i].i--;
    }
    rep(m,0,1<<N) {
        rep(i,0,N) {
            dp[m][i] = 1e9;
        }
    }
    rep(i,0,N) {
        rep(j,0,N) {
            if (i == j) continue;
            int x = 0;
            int y = 1;
            int cur = 1;
            rep(k,0,Q) {
                if (q[k].i == i && q[k].c == '+') {
                    x++;
                } else if (q[k].i == j && q[k].c == '-') {
                    y++;
                }
                if (x == y) {
                    cur++;
                    y++;
                }
            }
            a[i][j] = cur;
        }
    }
    rep(m,1,1<<N) {
        rep(i,0,N) {
            if (m&(1<<i)) {
                if (m == 1<<i) {
                    dp[m][i] = 1;
                } else {
                    int n = m^(1<<i);
                    rep(j,0,N) {
                        if (n&(1<<j)) {
                            ckmin(dp[m][i], dp[n][j]+a[j][i]);
                        }
                    }
                }
            }
        }
    }
    ll ans = 1e18;
    rep(i,0,N) {
        ll cur = 0;
        pll p = {dp[(1<<N)-1][i],dp[(1<<N)-1][i]};
        // cout << "i: " << i << " " << p.x << " " << p.y << endl;
        rep(j,0,Q) {
            if (q[j].i == i && q[j].c == '+') {
                p.y++;
            } else if (q[j].i == i && q[j].c == '-') {
                p.x++;
            }
        }
        cur = p.y;
        ckmin(ans, cur);
    }
    cout << ans << endl;
    return 0;
}