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

int T, N, Q;
vt<ll> val[301][301];
vt<ll> pre[301][301];
vt<ll> dp[301][301];
ll a[100001];
int lim = 200;

int main () {
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        int top = ceil(sqrt(N));
        for (int sz = 1; sz <= min(lim, top); sz++) {
            for (int i = 0; i < sz; i++) {
                val[sz][i].clear();
                pre[sz][i].clear();
                dp[sz][i].clear();
            }
        }
        for (int sz = 1; sz <= min(lim, top); sz++) {
            for (int i = 0; i < sz; i++) {
                for (int j = i; j < N; j += sz) {
                    val[sz][i].push_back(a[j]);
                }
            }
        }
        for (int sz = 1; sz <= min(lim, top); sz++) {
            for (int i = 0; i < sz; i++) {
                pre[sz][i].push_back(0);
                dp[sz][i].push_back(0);
                for (ll j = 0; j < val[sz][i].size(); j++) {
                    pre[sz][i].push_back(pre[sz][i].back() + val[sz][i][j]);
                    dp[sz][i].push_back(dp[sz][i].back() + val[sz][i][j]*(j+1));
                }
            }
        }
        // cout << "dp: " << endl;
        // for (int sz = 1; sz <= min(lim, top); sz++) {
        //     for (int i = 0; i < sz; i++) {
        //         cout << "sz: " << sz << " i: " << i << endl;
        //         for (int j = 0; j < dp[sz][i].size(); j++) {
        //             cout << dp[sz][i][j] << " ";
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
        while (Q--) {
            int s, d, k;
            cin >> s >> d >> k;
            s--;
            if (d <= min(lim, top)) {
                // cout << "d: " << d << " s\%d: " << s%d << " s/d: " << s/d << " k: " << k << endl;
                ll res = dp[d][s%d][s/d+k];
                // cout << "res: " << res << endl;
                res -= dp[d][s%d][s/d];
                // cout << "res: " << res << endl;
                res -= s/d*(pre[d][s%d][s/d+k] - pre[d][s%d][s/d]);
                cout << res << " ";
            } else {
                ll ans = 0;
                for (int i = 0; i < k; i++) {
                    ans += (i+1)*a[s+i*d];
                }
                cout << ans << " ";
            }
        }
        cout << endl;
    }
}