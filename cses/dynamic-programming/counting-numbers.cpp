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

int T, N;
int a[200005];

ll solve(ll x) {
    string s = to_string(x);
    int n = sz(s);
    vt<vt<vt<ll>>> dp(n, vt<vt<ll>>(10, vt<ll>(2,0)));
    for (int i = 1; i < s[0]-'0'; i++) {
        dp[0][i][0] = 1;
    }
    dp[0][s[0]-'0'][1] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < s[i]-'0'; j++) {
            for (int k = 0; k < 10; k++) {
                if (j==k) continue;
                dp[i][j][0] += dp[i-1][k][1];
            }
        }
        for (int j = 0; j < 10; j++) {
            if (j==s[i]-'0') continue;
            dp[i][s[i]-'0'][1] += dp[i-1][j][1];
        }
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (j==k) continue;
                dp[i][j][0] += dp[i-1][k][0];
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += dp[n-1][i][0]+dp[n-1][i][1];
    }
    // cout << "x: " << x << " ans: " << ans << endl;
    return ans;
}

ll run(ll x) {
    if (x < 0) return 0;
    if (x==0) return 1;
    ll ans = 0;
    ll hm = 1;
    for (ll i = 0; i <= 18; i++) {
        if (hm-1 < x) {
            ans += solve(hm-1);
        }
        hm*=10;
    }
    ans += solve(x);
    // cout << "x: " << ans << endl;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll l, r; cin >> l >> r;
    ll lans = run(l-1), rans = run(r);
    cout << rans-lans << endl;
    return 0;
}