#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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

ll T, N, K, M;
ll dp[505][505][2];

ll add(ll a, ll b) {
    return (a+b)%M;
}

ll sub(ll a, ll b) {
    return (a-b+M)%M;
}

ll mul(ll a, ll b) {
    return (a*b)%M;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b%2) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, M-2);
}

ll di(ll a, ll b) {
    return mul(a, inv(b));
}

void solve1(ll n, ll k) {
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j][0] = dp[i][j-1][0];
            dp[i][j][1] = dp[i][j-1][1];
            for (int x = 0; x <= j; x++) {
                int y = j-x;
                dp[i][j][0] += dp[i-1][x][0]*dp[i-1][y][0];
                dp[i][j][0] %= M;
                if (x==y) continue;
                if (x>y) {
                    dp[i][j][1] += dp[i-1][x][1]*dp[i-1][y][0];
                    dp[i][j][1] %= M;
                } else {
                    dp[i][j][1] += dp[i-1][x][0]*dp[i-1][y][1];
                    dp[i][j][1] %= M;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K >> M;
        for (int i = 2; i <= N; i++) {
            for (int j = 0; j <= K; j++) {
                dp[i][j][0] = dp[i][j][1] = 0;
            }
        }
        for (int i = 0; i <= K; i++) {
            dp[1][i][0] = dp[1][i][1] = 1;
        }
        solve1(N, K);
        cout << dp[N][K][1] << endl;
    }
    return 0;
}