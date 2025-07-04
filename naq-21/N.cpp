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
bool vowel[128];
int val[128];

ll ad(ll a, ll b) {
    return (a+b)%MOD2;
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD2;
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
    return binpow(a, MOD2-2);
}

ll di(ll a, ll b) {
    return mul(a, inv(b));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string v = "AEIOUaeiou";
    string c = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
    int cnt = 0;
    for (char c : v) val[c] = cnt++;
    cnt = 0;
    for (char c : c) val[c] = cnt++;
    for (char c : v) vowel[c] = 1;
    string s; cin >> s;
    N = sz(s);
    ll ans = 0;
    vt<ll> dp(5,0);
    for (int i = 0; i < N; i++) {
        if (vowel[s[i]]) {
            dp[0] = ad(dp[0], 1);
            dp[2] = ad(dp[2], dp[1]);
            dp[4] = ad(dp[4], dp[3]);
        } else {
            dp[1] = ad(dp[1], dp[0]);
            dp[3] = ad(dp[3], dp[2]);
        }
    }
    ans = ad(ans, dp[4]);
    //24 same
    vt<vt<ll>> dp1(5,vt<ll>(42,0));
    for (int i = 0; i < N; i++) {
        int va = val[s[i]];
        if (vowel[s[i]]) {
            dp1[0][0] = ad(dp1[0][0], 1);
            for (int j = 0; j < 42; j++) {
                dp1[2][j] = ad(dp1[2][j], dp1[1][j]);
                dp1[4][j] = ad(dp1[4][j], dp1[3][j]);
            }
        } else {
            dp1[1][va] = ad(dp1[1][va], dp1[0][0]);
            dp1[3][va] = ad(dp1[3][va], dp1[2][va]);
        }
    }
    for (int i = 0; i < 42; i++) {
        ans = sub(ans, dp1[4][i]);
    }
    //13 same
    dp1 = vt<vt<ll>>(5,vt<ll>(10,0));
    for (int i = 0; i < N; i++) {
        int va = val[s[i]];
        if (vowel[s[i]]) {
            dp1[0][va] = ad(dp1[0][va], 1);
            dp1[2][va] = ad(dp1[2][va], dp1[1][va]);
            for (int j = 0; j < 10; j++) {
                dp1[4][j] = ad(dp1[4][j], dp1[3][j]);
            }
        } else {
            for (int j = 0; j < 10; j++) {
                dp1[1][j] = ad(dp1[1][j], dp1[0][j]);
                dp1[3][j] = ad(dp1[3][j], dp1[2][j]);
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        ans = sub(ans, dp1[4][i]);
    }
    //35 same
    dp1 = vt<vt<ll>>(5,vt<ll>(10,0));
    for (int i = 0; i < N; i++) {
        int va = val[s[i]];
        if (vowel[s[i]]) {
            dp1[0][0] = ad(dp1[0][0], 1);
            dp1[2][va] = ad(dp1[2][va], dp1[1][0]);
            dp1[4][va] = ad(dp1[4][va], dp1[3][va]);
        } else {
            for (int j = 0; j < 10; j++) {
                dp1[1][j] = ad(dp1[1][j], dp1[0][j]);
                dp1[3][j] = ad(dp1[3][j], dp1[2][j]);
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        ans = sub(ans, dp1[4][i]);
    }
    //15 same
    dp1 = vt<vt<ll>>(5,vt<ll>(10,0));
    for (int i = 0; i < N; i++) {
        int va = val[s[i]];
        if (vowel[s[i]]) {
            dp1[0][va] = ad(dp1[0][va], 1);
            for (int j = 0; j < 10; j++) {
                dp1[2][j] = ad(dp1[2][j], dp1[1][j]);
            }
            dp1[4][va] = ad(dp1[4][va], dp1[3][va]);
        } else {
            for (int j = 0; j < 10; j++) {
                dp1[1][j] = ad(dp1[1][j], dp1[0][j]);
                dp1[3][j] = ad(dp1[3][j], dp1[2][j]);
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        ans = sub(ans, dp1[4][i]);
    }
    //13 24 same
    vt<vt<vt<ll>>> dp2(5,vt<vt<ll>>(42,vt<ll>(10,0)));
    for (int i = 0; i < N; i++) {
        int va = val[s[i]];
        if (vowel[s[i]]) {
            dp2[0][0][va] = ad(dp2[0][0][va], 1);
            for (int j = 0; j < 42; j++) {
                dp2[2][j][va] = ad(dp2[2][j][va], dp2[1][j][va]);
            }
            for (int j = 0; j < 42; j++) {
                for (int k = 0; k < 10; k++) {
                    dp2[4][j][k] = ad(dp2[4][j][k], dp2[3][j][k]);
                }
            }
        } else {
            for (int j = 0; j < 10; j++) {
                dp2[1][va][j] = ad(dp2[1][va][j], dp2[0][0][j]);
                dp2[3][va][j] = ad(dp2[3][va][j], dp2[2][va][j]);
            }
        }
    }
    for (int i = 0; i < 42; i++) {
        for (int j = 0; j < 10; j++) {
            ans = ad(ans, dp2[4][i][j]);
        }
    }
    //15 24 same
    dp2 = vt<vt<vt<ll>>>(5,vt<vt<ll>>(42,vt<ll>(10,0)));
    for (int i = 0; i < N; i++) {
        int va = val[s[i]];
        if (vowel[s[i]]) {
            dp2[0][0][va] = ad(dp2[0][0][va], 1);
            for (int j = 0; j < 42; j++) {
                for (int k = 0; k < 10; k++) {
                    dp2[2][j][k] = ad(dp2[2][j][k], dp2[1][j][k]);
                }
            }
            for (int j = 0; j < 42; j++) {
                dp2[4][j][va] = ad(dp2[4][j][va], dp2[3][j][va]);
            }
        } else {
            for (int j = 0; j < 10; j++) {
                dp2[1][va][j] = ad(dp2[1][va][j], dp2[0][0][j]);
                dp2[3][va][j] = ad(dp2[3][va][j], dp2[2][va][j]);
            }
        }
    }
    for (int i = 0; i < 42; i++) {
        for (int j = 0; j < 10; j++) {
            ans = ad(ans, dp2[4][i][j]);
        }
    }
    //35 24 same
    dp2 = vt<vt<vt<ll>>>(5,vt<vt<ll>>(42,vt<ll>(10,0)));
    for (int i = 0; i < N; i++) {
        int va = val[s[i]];
        if (vowel[s[i]]) {
            dp2[0][0][0] = ad(dp2[0][0][0], 1);
            for (int j = 0; j < 42; j++) {
                dp2[2][j][va] = ad(dp2[2][j][va], dp2[1][j][0]);
            }
            for (int j = 0; j < 42; j++) {
                dp2[4][j][va] = ad(dp2[4][j][va], dp2[3][j][va]);
            }
        } else {
            for (int j = 0; j < 10; j++) {
                dp2[1][va][j] = ad(dp2[1][va][j], dp2[0][0][j]);
                dp2[3][va][j] = ad(dp2[3][va][j], dp2[2][va][j]);
            }
        }
    }
    for (int i = 0; i < 42; i++) {
        for (int j = 0; j < 10; j++) {
            ans = ad(ans, dp2[4][i][j]);
        }
    }
    //13 35 same
    dp1 = vt<vt<ll>>(5,vt<ll>(10,0));
    for (int i = 0; i < N; i++) {
        int va = val[s[i]];
        if (vowel[s[i]]) {
            dp1[0][va] = ad(dp1[0][va], 1);
            dp1[2][va] = ad(dp1[2][va], dp1[1][va]);
            dp1[4][va] = ad(dp1[4][va], dp1[3][va]);
        } else {
            for (int j = 0; j < 10; j++) {
                dp1[1][j] = ad(dp1[1][j], dp1[0][j]);
                dp1[3][j] = ad(dp1[3][j], dp1[2][j]);
            }
        }
    }
    ll res = 0;
    for (int i = 0; i < 10; i++) {
        res = ad(res, dp1[4][i]);
    }
    ans = ad(ans, mul(2,res));
    //13 35 24 same
    dp2 = vt<vt<vt<ll>>>(5,vt<vt<ll>>(42,vt<ll>(10,0)));
    for (int i = 0; i < N; i++) {
        int va = val[s[i]];
        if (vowel[s[i]]) {
            dp2[0][0][va] = ad(dp2[0][0][va], 1);
            for (int j = 0; j < 42; j++) {
                dp2[2][j][va] = ad(dp2[2][j][va], dp2[1][j][va]);
            }
            for (int j = 0; j < 42; j++) {
                dp2[4][j][va] = ad(dp2[4][j][va], dp2[3][j][va]);
            }
        } else {
            for (int j = 0; j < 10; j++) {
                dp2[1][va][j] = ad(dp2[1][va][j], dp2[0][0][j]);
                dp2[3][va][j] = ad(dp2[3][va][j], dp2[2][va][j]);
            }
        }
    }
    res = 0;
    for (int i = 0; i < 42; i++) {
        for (int j = 0; j < 10; j++) {
            res = ad(res, dp2[4][i][j]);
        }
    }
    ans = sub(ans, mul(2,res));
    cout << ans << endl;
    return 0;
}