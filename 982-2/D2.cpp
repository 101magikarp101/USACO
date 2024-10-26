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
        vt<vt<int>> dp2(N+1, vt<int>(M+1, 0));
        vt<ll> best(N+1,1e18);
        vt<int> best2(N+1,0);
        dp[0][0] = 0;
        best[0] = 0;
        best2[0] = 1;
        for (int j = 1; j <= M; j++) {
            // cout << "b[" << j << "] = " << b[j] << endl;
            map<ll,ll> m;
            m[0] = 1;
            dp[0][j] = 0;
            int l = 1;
            ll sum = 0;
            for (int i = 1; i <= N; i++) {
                // dp[i][j] = dp[i-1][j];
                // cout << "i = " << i << " j = " << j << endl;
                // cout << "m:" << endl;
                // for (auto &x : m) {
                //     cout << x.first << " " << x.second << endl;
                // }

                sum += a[i];
                while (sum > b[j] && l < i) {
                    // cout << "sub " << m[best[l-1]] << " " << best2[l-1] << endl;
                    m[best[l-1]] = sub(m[best[l-1]], best2[l-1]);
                    sum -= a[l++];
                }
                // cout << "i = " << i << " l = " << l << " sum = " << sum << endl;
                if (sum > b[j]) {
                    m[best[i]] = ad(m[best[i]], best2[i]);
                    continue;
                }
                // cout << "sum = " << sum << endl;
                dp[i][j] = min(dp[i][j], best[l-1]+M-j);
                dp2[i][j] = m[best[l-1]];
                // cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
                // best[i] = min(best[i], dp[i][j]);
                if (dp[i][j] < best[i]) {
                    best[i] = dp[i][j];
                    best2[i] = dp2[i][j];
                } else if (dp[i][j] == best[i]) {
                    best2[i] = ad(best2[i], dp2[i][j]);
                }
                m[best[i]] = ad(m[best[i]], best2[i]);
            }
        }
        // cout << "dp:" << endl;
        // for (int i = 0; i <= N; i++) {
        //     for (int j = 0; j <= M; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "dp2:" << endl;
        // for (int i = 0; i <= N; i++) {
        //     for (int j = 0; j <= M; j++) {
        //         cout << dp2[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if (best[N] >= 1e18) {
            cout << -1 << endl;
        } else {
            cout << best[N] << " " << best2[N] << endl;
        }
    }
    return 0;
}