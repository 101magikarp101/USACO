#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

int N, M, K;
map<int, vt<int>> m;

int ad(int a, int b) {
    return (a+b)%MOD;
}

int sub(int a, int b) {
    return (a-b+MOD)%MOD;
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

struct state {
    int x, mi, ma;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        int x, y; cin >> x >> y;
        m[y].pb(x);
    }
    for (auto &x : m) {
        sort(all(x.se));
    }
    vt<state> v;
    for (auto &x : m) {
        v.pb({x.fi, x.se[0], x.se[sz(x.se)-1]});
    }
    vt<int> dp(2,0);
    ll sus = 0;
    for (int i = 0; i < sz(v); i++) {
        int x = v[i].x;
        int mi = v[i].mi;
        int ma = v[i].ma;
        if (i == 0) {
            if (x == 1) {
                dp[1] = 1;
                dp[0] = 0;
            } else {
                ll hm = binpow(N, x-2);
                dp[1] = mul(hm, ma);
                dp[0] = mul(hm, N-mi+1);
                if (mi == ma) {
                    sus = hm;
                }
            }
        } else {
            ll a = 0, b = 0;
            if (x == v[i-1].x+1) {
                ll res = min(N-mi+1, N-v[i-1].ma+1);
                a = mul(dp[1], res);
                res = min(ma, v[i-1].mi);
                b = mul(dp[0], res);
                if (mi == ma) {
                    if (mi)
                }
                dp[0] = a;
                dp[1] = b;
            } else {
                ll hm = mul(ad(dp[0], dp[1]), binpow(N, x-v[i-1].x-2));
                dp[1] = mul(hm, ma);
                dp[0] = mul(hm, N-mi+1);
            }
        }
    }
    cout << ad(dp[0], dp[1]) << endl;
    return 0;
}