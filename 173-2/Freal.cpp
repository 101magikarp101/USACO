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
int cnt[100005][51];
pii dp[52][64][2]; // {num of elements, num of ways}

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

void merge(pii &a, pii b) {
    if (a.x == b.x) a.y = ad(a.y, b.y);
    if (a.x > b.x) a = b;
}

pii solve(int l, int r) {
    rep(i,0,52) {
        rep(j,0,64) {
            dp[i][j][0] = {(int)1e9,0};
            dp[i][j][1] = {(int)1e9,0};
        }
    }
    dp[0][0][0] = {0,1};
    rep(i,1,52) {
        int c = cnt[r][i-1] - cnt[l-1][i-1];
        int c2 = (c>=2?di(mul(c,c-1),2):0);
        rep(j,0,64) {
            //choose 0
            merge(dp[i][j][0], dp[i-1][j][0]);
            merge(dp[i][j][1], dp[i-1][j][1]);
            //choose 1
            if (c>=1) merge(dp[i][j^(i-1)][1], {dp[i-1][j][0].x+1,mul(dp[i-1][j][0].y,c)});
            if (c>=1) merge(dp[i][j^(i-1)][1], {dp[i-1][j][1].x+1,mul(dp[i-1][j][1].y,c)});
            //choose 2
            if (c>=2) merge(dp[i][j][1], {dp[i-1][j][0].x+2,c2});
            if (c>=2) merge(dp[i][j][1], {dp[i-1][j][1].x+2,c2});
        }
    }
    return dp[51][0][1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    rep(i,1,N+1) {
        int x; cin >> x;
        rep(j,0,51) cnt[i][j] = cnt[i-1][j];
        cnt[i][x]++;
    }
    while (Q--) {
        int l, r; cin >> l >> r;
        pii ans = solve(l,r);
        if (ans.x == 1e9) {
            cout << -1 << endl;
        } else {
            cout << r-l+1-ans.x << " " << ans.y << endl;
        }
    }
    return 0;
}