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

int N, M;
int cat[505][505];
int dp[505][505][505];
int pre[505][505];

int c(int n, int k) {
    if (k <= n-k) return cat[n-k][k];
    else return cat[k][n-k];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cat[0][0] = 1;
    for (int i = 1; i <= 500; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) cat[i][j] = cat[i-1][j];
            else if (j == i) cat[i][j] = cat[i][j-1];
            else cat[i][j] = ad(cat[i-1][j], cat[i][j-1]);
        }
    }
    cin >> N >> M;
    if (N==1) {
        cout << c(M,M/2) << endl;
        return 0;
    }
    for (int i = M/2; i <= M; i++) {
        dp[1][i][i-M/2] = c(M,i);
        pre[1][i-M/2] = ad(pre[1][i-M/2], dp[1][i][i-M/2]);
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= M/2; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j][k] = mul(c(M,j), pre[i-1][M/2-j+k]);
                pre[i][k] = ad(pre[i][k], dp[i][j][k]);
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= M/2; j++) {
        ans = ad(ans, dp[N][j][0]);
    }
    cout << ans << endl;
    return 0;
}