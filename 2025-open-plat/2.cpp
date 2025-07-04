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
pll a[105];
int fact[5000005], invfact[5000005];
int invi[5000005];
int dp[105][2];

int nck(int n, int k) {
    if (n < k) return 0;
    return mul(fact[n], mul(invfact[k], invfact[n-k]));
}

int solve(int n, int k) {
    if (k < 0) return 0;
    int ans = 0;
    int res = 1;
    rep(i,0,n) {
        // ans = ad(ans, mul(nck(k+i,i), nck(n-1,i)));
        ans = ad(ans, mul(res, nck(n-1,i)));
        res = mul(res, k+i+1);
        res = mul(res, invi[i+1]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    fact[0] = 1;
    rep(i,1,5000005) {
        fact[i] = mul(fact[i-1], i);
    }
    invfact[5000004] = inv(fact[5000004]);
    rrep(i,5000003,0) {
        invfact[i] = mul(invfact[i+1], i+1);
    }
    rep(i,0,5000005) {
        invi[i] = inv(i);
    }
    cin >> N >> Q;
    rep(i,0,Q) {
        cin >> a[i].x >> a[i].y;
    }
    dp[0][0] = 1;
    dp[0][1] = 0;
    bool bad = 0;
    rep(i,1,Q) {
        int dx = a[i].x-a[i-1].x;
        int dy = a[i].y-a[i-1].y;
        int r1 = solve(dx, dy);
        int r2 = solve(dx, dy+1);
        int r3 = solve(dx, dy-1);
        // cout << "i: " << i << " r1: " << r1 << " r2: " << r2 << " r3: " << r3 << endl;
        if (dy == -1) {
            dp[i][1] = ad(dp[i][1], mul(dp[i-1][0], binpow(2, dx-1)));
        } else if (dy < -1) {
            bad = 0;
            break;
        } else {
            dp[i][0] = ad(dp[i][0], mul(dp[i-1][0], r1));
            dp[i][1] = ad(dp[i][1], mul(dp[i-1][0], sub(r2,r1)));        
            dp[i][0] = ad(dp[i][0], mul(dp[i-1][1], r3));
            dp[i][1] = ad(dp[i][1], mul(dp[i-1][1], sub(r1,r3)));
        }
    }
    if (bad) {
        cout << 0 << endl;
        return 0;
    }
    // cout << "dp" << endl;
    // rep(i,0,Q) {
    //     cout << dp[i][0] << " " << dp[i][1] << endl;
    // }
    cout << ad(dp[Q-1][0], dp[Q-1][1]) << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}