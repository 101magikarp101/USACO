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
struct pii {int x, y;};
struct pll {int x, y;};

struct state {
    ll t, d;
};

ll L, R, N, K;
int arr[100005];
vt<vt<ll>> dp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> R >> N >> K;
    dp = vt<vt<ll>>(1<<R, vt<ll>(N+1, LLONG_MAX));
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    dp[1][0] = 0;
    ll T = L*K/R;
    for (int m = 1; m < (1<<R); m+=2) {
        for (int i = 1; i < R; i++) {
            if (m&(1<<i)) {
                ll mprev = m^(1<<i);
                // cout << "mprev: " << mprev << endl;
                // cout << "i: " << i << endl;
                if (!(mprev&1)) continue;
                for (int a = 0; a <= N; a++) {
                    if (dp[mprev][a]==LLONG_MAX) continue;
                    for (int b = 1; b <= N; b++) {
                        ll d = abs(arr[b]-(a==0?0:arr[a]));
                        d = min(d, L-d);
                        ll x = dp[mprev][a]/K+i*L/R;
                        // cout << "d: " << d << " x: " << x << endl;
                        x%=L;
                        ll x1 = (arr[b]-x)*K;
                        // cout << "x: " << x << " x1: " << x1 << endl;
                        if (x1<0) x1+=L*K;
                        if (x1<d) x1+=L*K;
                        // cout << "a: " << a << " b: " << b << " x1: " << x1 << " d: " << d << endl;
                        dp[m][b] = min(dp[m][b], dp[mprev][a]+x1);
                        // cout << "dp[" << m << "][" << b << "]: " << dp[m][b] << endl;
                    }
                }
            }
        }
    }
    ll ans = LLONG_MAX;
    for (int i = 0; i <= N; i++) {
        ans = min(ans, dp[(1<<R)-1][i]);
    }
    cout << ans << endl;
    return 0;
}