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

struct cow {
    ll h, w, s;
};

struct state {
    ll h, s;
};

int N;
ll H;
state dp[1 << 20];
cow arr[20];

int main () {
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    cin >> N >> H;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].h >> arr[i].w >> arr[i].s;
    }
    dp[0] = {0, (ll)1e18};
    for (int i = 1; i < (1 << N); i++) {
        dp[i] = {0, -1};
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                dp[i].h += arr[j].h;
                int pre = i ^ (1 << j);
                ll ns = min(dp[pre].s - arr[j].w, arr[j].s);
                dp[i].s = max(dp[i].s, ns);
            }
        }
    }
    ll ans = -1;
    for (int i = 1; i < (1 << N); i++) {
        // cout << "i: " << i << " h: " << dp[i].h << " s: " << dp[i].s << endl;
        if (dp[i].h >= H) {
            ans = max(ans, dp[i].s);
        }
    }
    if (ans < 0) {
        cout << "Mark is too tall" << endl;
    } else {
        cout << ans << endl;
    }
}