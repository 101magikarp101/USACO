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

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

ll T, N, K;
ll D;
ll a[2002];
ll v[2002];
ll dp[2002];

ll count() {
    ll cnt = 0;
    ll d = 0;
    for (ll i = 1; i <= N; i++) {
        d += dp[i];
        if (a[i] + d == i) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> T;
    while (T--) {
        memset(dp, 0, sizeof(dp));
        cin >> N >> K >> D;
        for (ll i = 1; i <= N; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i < K; i++) {
            cin >> v[i];
        }
        ll c = count();
        ll ans = c;
        ll t = 1;
        double best = (double)(ans)/(double)(t);
        // cout << "ans: " << ans << endl;
        for (ll i = 0; i < K; i++) {
            dp[1]++;
            dp[v[i] + 1]--;
            ll cnt = count();
            // cout << "i: " << i << " cnt: " << cnt << endl;
            if (K == D && i == K-1) {
                break;
            }
            double res = (double)(cnt)/(double)(i+2);
            if (res > best) {
                best = res;
                ans = cnt;
                t = i+2;
            }
        }
        D -= t;
        ans += D/2;
        ll ans1;
        if (c >= 1) {
            ans1 = c + (D-1)/2;
        } else {
            ans1 = D/2;
        }
        // cout << "t: " << t << " best: " << best << " c: " << c << endl;
        // cout << "ans: " << ans << " ans1: " << ans1 << endl;
        if (ans1 > ans) {
            ans = ans1;
        }
        cout << ans << endl;
    }
}