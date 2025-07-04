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

int T, N, M;
ll a[300005], b[300005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= M; i++) {
            cin >> b[i];
        }
        vt<vt<ll>> dp(N+1, vt<ll>(M+1, 1e18));
        vt<ll> best(N+1,1e18);
        dp[0][0] = 0;
        best[0] = 0;
        for (int j = 1; j <= M; j++) {
            // cout << "b[" << j << "] = " << b[j] << endl;
            dp[0][j] = 0;
            int l = 1;
            ll sum = 0;
            for (int i = 1; i <= N; i++) {
                // dp[i][j] = dp[i-1][j];
                sum += a[i];
                while (sum > b[j] && l <= i) {
                    sum -= a[l++];
                }
                cout << "i = " << i << " l = " << l << " sum = " << sum << endl;
                if (sum > b[j]) continue;
                // cout << "sum = " << sum << endl;
                dp[i][j] = min(dp[i][j], best[l-1]+M-j);
                cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
                best[i] = min(best[i], dp[i][j]);
            }
        }
        cout << (best[N] >= 1e18 ? -1 : best[N]) << endl;
    }
    return 0;
}