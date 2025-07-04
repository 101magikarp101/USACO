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

int T, N;
ll a[300005];
vt<ll> dp;
vt<ll> pre;
deque<int> dq;

ll add(ll a, ll b) {
    return (a + b+2*MOD) % MOD;
}

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        dq.clear();
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        dp = vt<ll>(N+1,0);
        pre = vt<ll>(N+1,0);
        ll sum = 0;
        dq.push_back(0);
        for (int i = 1; i <= N; i++) {
            while (!dq.empty() && a[dq.back()] > a[i]) {
                sum -= dp[dq.back()];
                dq.pop_back();
            }
            if (dq.size() == 1) {
                dp[i] = add(dp[i], pre[i-1]+1);
            } else {
                int x = dq.back();
                dp[i] = add(dp[i], sum);
                dp[i] = add(dp[i], pre[i-1]-pre[x]);
            }
            pre[i] = add(pre[i-1], dp[i]);
            sum = add(sum, dp[i]);
            dq.push_back(i);
        }
        ll min = 1e9+2;
        ll ans = 0;
        for (int i = N; i >= 1; i--) {
            if (a[i] < min) {
                min = a[i];
                ans = add(ans, dp[i]);
            }
        }
        cout << ans << endl;
    }
}