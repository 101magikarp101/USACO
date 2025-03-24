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
#define repl(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define rrepl(i,a,b) for(ll i=a;i>=b;i--)
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

int ad(int a, int b) {
    a+=b;
    if (a>=MOD2) a-=MOD2;
    return a;
}

int sub(int a, int b) {
    a-=b;
    if (a<0) a+=MOD2;
    return a;
}

int mul(int a, int b) {
    return (int)((a*1LL*b)%MOD2);
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
    return binpow(a, MOD2-2);
}

int di(int a, int b) {
    return mul(a, inv(b));
}

int N, Q;
int a[5000005];
int dp[1000005][2][2], pre[1000005][2][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> Q;
    rep(i,1,N+1) a[i] = 0;
    int MAX = 1e6;
    rep(q,0,Q) {
        int i, v; cin >> i >> v;
        a[i] = v;
    }
    dp[a[1]][0][0] = 1;
    dp[a[1]][1][0] = 0;
    rep(i,a[1],MAX+1) {
        pre[i][0][0] = 1;
        pre[i][1][0] = 0;
    }
    rep(i,2,N+1) {
        if (a[i] != 0) {
            dp[a[i]][0][1] = ad(dp[a[i]][0][1], pre[a[i]-1][1][0]);
            dp[a[i]][0][1] = ad(dp[a[i]][0][1], pre[a[i]][0][0]);
            dp[a[i]][1][1] = ad(dp[a[i]][1][1], dp[a[i]+1][0][0]);
            dp[a[i]][1][1] = ad(dp[a[i]][1][1], dp[a[i]][1][0]);
        } else {    
            rep(j,0,MAX+1) {
                dp[j][0][1] = ad(dp[j][0][1], pre[j][0][0]);
                if (j) dp[j][0][1] = ad(dp[j][0][1], pre[j-1][1][0]);
                dp[j][1][1] = ad(dp[j][1][1], dp[j][1][0]);
                dp[j][1][1] = ad(dp[j][1][1], dp[j+1][0][0]);
            }
        }
        rep(j,0,MAX+1) {
            rep(k,0,2) {
                pre[j][k][1] = dp[j][k][1];
                if (j) pre[j][k][1] = ad(pre[j][k][1], pre[j-1][k][1]);
                pre[j][k][0] = pre[j][k][1];
                dp[j][k][0] = dp[j][k][1];
                dp[j][k][1] = 0;
            }
        }
        // if (a[i] != 0) {
        //     cout << dp[a[i]][0][0] << " " << dp[a[i]][0][1] << " " << dp[a[i]][1][0] << " " << dp[a[i]][1][1] << endl;
        // }
        // cout << "i: " << i << endl;
        // rep(j,0,12) {
        //     cout << j << ": " << pre[j][0][0] << " " << pre[j][0][1] << " " << pre[j][1][0] << " " << pre[j][1][1] << endl;
        // }
    }
    int ans = 0;
    rep(i,0,MAX+1) {
        ans = ad(ans, dp[i][0][0]);
        ans = ad(ans, dp[i][1][0]);
    }
    cout << ans << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}