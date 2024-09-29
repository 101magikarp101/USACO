#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
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

struct sus {
    ll x, y, z;
};

int T, N;
sus a[200005];
int dp[2][1024];

void add(int &a, int b) {
    a += b;
    if (a >= MOD2) a -= MOD2;
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

int sub(int a, int b) {
    a -= b;
    if (a < 0) a += MOD2;
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int hm = binpow(10000, MOD2-2);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i].x;
        }
        for (int i = 0; i < N; i++) {
            cin >> a[i].y;
            a[i].y = mul(a[i].y, hm);
            a[i].z = sub(1, a[i].y);
        }
        for (int i = 0; i < 1024; i++) {
            dp[0][i] = 0;
        }
        dp[0][0] = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 1024; j++) {
                dp[1][j] = mul(dp[0][j], a[i].z);
            }
            for (int j = 0; j < 1024; j++) {
                add(dp[1][j^a[i].x], mul(dp[0][j], a[i].y));
            }
            for (int j = 0; j < 1024; j++) {
                dp[0][j] = dp[1][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < 1024; i++) {
            add(ans, mul(i*i, dp[0][i]));
        }
        cout << ans << endl;
    }
    return 0;
}