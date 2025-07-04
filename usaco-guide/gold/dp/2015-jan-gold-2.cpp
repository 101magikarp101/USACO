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

struct movie {
    ll d;
    vt<ll> c;
};

int N;
ll L;
ll dp[1 << 20];
movie arr[20];

int main () {
    freopen("movie.in", "r", stdin);
    freopen("movie.out", "w", stdout);
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].d;
        ll cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            ll a;
            cin >> a;
            arr[i].c.push_back(a);
        }
    }
    dp[0] = 0;
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                ll pre = i ^ (1 << j);
                ll t = dp[pre];
                int idx = upper_bound(arr[j].c.begin(), arr[j].c.end(), t) - arr[j].c.begin();
                idx--;
                // cout << "i: " << i << " j: " << j << " pre: " << pre << " t: " << t << " idx: " << idx << endl;
                if (idx < 0) continue;
                ll t1 = arr[j].c[idx]+arr[j].d;
                if (t1 <= t) continue;
                dp[i] = max(dp[i], t1);
            }
        }
    }
    int ans = 1000;
    for (int i = 0; i < (1 << N); i++) {
        // cout << "i: " << i << " dp: " << dp[i] << endl;
        if (dp[i] >= L) {
            ans = min(ans, __builtin_popcount(i));
        }
    }
    if (ans == 1000) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}