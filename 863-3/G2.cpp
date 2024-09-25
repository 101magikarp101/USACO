#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>
#include <unordered_map>
#include <deque>
#include <climits>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct state {
    ll l, n;
};

int T, K, N;
ll a[5002];
state dp[5002];
ll fac[5002];
ll in[5002];

ll add(ll a, ll b) {
    return (a+b)%MOD2;
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    ll res = binpow(a, b/2);
    if (b%2) {
        return mul(mul(res, res), a);
    } else {
        return mul(res, res);
    }
}

ll inv(ll a) {
    return binpow(a, MOD2-2);
}

ll nck(ll n, ll k) {
    if (k > n) return 0;
    if (n < 0 || k < 0) return 0;
    return mul(mul(fac[n], in[k]), in[n-k]);
}

int main () {
    fac[0] = 1;
    for (int i = 1; i <= 5000; i++) {
        fac[i] = mul(fac[i-1], i);
    }
    for (int i = 0; i <= 5000; i++) {
        in[i] = inv(fac[i]);
    }
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
            dp[i] = {0, 0};
        }
        dp[0] = {0, 1};
        for (int i = 0; i <= N; i++) {
            map<int, int> cnt;
            for (int j = i+1; j <= N; j++) {
                cnt[a[j]]++;
                if (cnt[a[j]] >= K) {
                    if (dp[i].l+1 > dp[j].l) {
                        dp[j] = {dp[i].l+1, mul(dp[i].n, nck(cnt[a[j]]-1, K-1))};
                    } else if (dp[i].l+1 == dp[j].l) {
                        dp[j].n = add(dp[j].n, mul(dp[i].n, nck(cnt[a[j]]-1, K-1)));
                    }
                }
            }
        }
        // cout << "dp: " << endl;
        // for (int i = 1; i <= N; i++) {
        //     cout << dp[i].l << " " << dp[i].n << endl;
        // }
        ll ma = -1;
        ll ans = 0;
        for (int i = 0; i <= N; i++) {
            if (dp[i].l > ma) {
                ma = dp[i].l;
                ans = dp[i].n;
            } else if (dp[i].l == ma) {
                ans = add(ans, dp[i].n);
            }
        }
        cout << ans << endl;
    }
}