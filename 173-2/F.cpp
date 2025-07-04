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

int T, N, Q;
int a[100005];

int ad(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int sub(int a, int b) {
    a-=b;
    if (a<0) a+=MOD;
    return a;
}

int mul(int a, int b) {
    return (int)((a*1LL*b)%MOD);
}

int binpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return binpow(a, MOD-2);
}

int di(int a, int b) {
    return mul(a, inv(b));
}

pii merge(pii a, pii b) {
    if (a.y == b.y) return {ad(a.x, b.x), a.y};
    if (a.y < b.y) return a;
    return b;
}

pii solve(int l, int r) {
    vt<vt<pii>> dp(r-l+1, vt<pii>(64,{0,(int)1e9})); // dp[i][j] = {ways, number}
    rep(i,l,r+1) {
        int j = i-l;
        if (j!=0) {
            rep(k,0,64) {
                dp[j][k^a[i]] = merge(dp[j][k^a[i]], {dp[j-1][k].x, dp[j-1][k].y+1});
                dp[j][k] = merge(dp[j][k], dp[j-1][k]);
            }
        }
        dp[j][a[i]] = merge(dp[j][a[i]], {1, 1});
    }
    // cout << "dp" << endl;
    // rep(i,0,r-l+1) {
    //     rep(j,0,64) {
    //         cout << "(" << dp[i][j].x << "," << dp[i][j].y << ") ";
    //     }
    //     cout << endl;
    // }
    return dp[r-l][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    rep(i,1,N+1) {
        cin >> a[i];
    }
    while (Q--) {
        int l, r; cin >> l >> r;
        pii ans = solve(l, r);
        if (ans.y == 1e9) {
            cout << -1 << endl;
            continue;
        }
        cout << r-l+1-ans.y << " " << ans.x << endl;
    }
    return 0;
}