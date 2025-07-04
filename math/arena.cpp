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
#include <unordered_set>
 
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, X;
ll dp[502][502];
ll fac[502];
ll bpow[502][502];
ll invfac[502];

ll add(ll a, ll b) {
    return (a+b)%MOD;
}

ll mult(ll a, ll b) {
    return (a*b)%MOD;
}

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll res = binpow(a, b/2);
    res = mult(res, res);
    if (b%2) res = mult(res, a);
    return res;
}

ll nck(ll n, ll k) {
    if (k > n) return 0;
    if (k < 0) return 0;
    return mult(mult(fac[n], invfac[k]), invfac[n-k]);
}

int main () {
    fac[0] = 1;
    for (ll i = 1; i <= 500; i++) {
        fac[i] = mult(fac[i-1], i);
    }
    for (ll i = 1; i <= 500; i++) {
        for (ll j = 0; j <= 500; j++) {
            if (j == 0) {
                bpow[i][j] = 1;
            } else {
                bpow[i][j] = mult(bpow[i][j-1], i);
            }
        }
    }
    for (ll i = 0; i <= 500; i++) {
        invfac[i] = binpow(fac[i], MOD-2);
    }
    cin >> N >> X;
    for (int i = 1; i <= X; i++) {
        dp[0][i] = 1;
        dp[1][i] = 0;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= X; j++) {
            if (j <= i-1) {
                dp[i][j] = bpow[j][i];
            } else {
                for (int k = 0; k <= i; k++) {
                    ll res = mult(mult(nck(i, k), dp[i-k][j-(i-1)]), bpow[i-1][k]);
                    // cout << "i: " << i << " j: " << j << " k: " << k << " res: " << res << endl;
                    dp[i][j] = add(dp[i][j], res);
                }
            }
        }
    }
    // cout << "dp: " << endl;
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= X; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[N][X] << endl;
}