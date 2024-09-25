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

int T, K, N;
ll a[102];
ll dp[102][102];
ll fac[102];
ll in[102];

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
    for (int i = 1; i <= 100; i++) {
        fac[i] = mul(fac[i-1], i);
    }
    for (int i = 0; i <= 100; i++) {
        in[i] = inv(fac[i]);
    }
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        dp[0][0] = 1;
        for (int i = 1; i <= N; i++) {
            memset(dp[i], 0, sizeof(dp[i]));
            int cnt = 0;
            for (int j = i; j >= 0; j--) {
                if (cnt >= K) {
                    for (int k = 0; k <= 5000; k++) {
                        dp[i][k+1] = add(dp[i][k+1], mul(nck(cnt-1, K-1), dp[j][k]));
                        // if (dp[i][k+1]!=0) cout << "dp[" << i << "][" << k+1 << "] = " << dp[i][k+1] << endl;
                    }
                }
                if (a[j] == a[i]) {
                    cnt++;
                }
            }
        }
        ll ans = 0;
        for (int j = 5000; j >= 0; j--) {
            bool good = false;
            for (int i = 1; i <= N; i++) {
                if (dp[i][j] > 0) {
                    good = true;
                    ans = add(ans, dp[i][j]);
                }
            }
            if (good) {
                break;
            }
        }
        cout << max(1LL, ans) << endl;
    }
}