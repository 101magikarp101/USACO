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
#define MOD 1000000007

using namespace std;

ll T, N, M, K;
vector<vector<ll>> a;
vector<vector<ll>> dp;

ll get(ll i1, ll j1, ll i2, ll j2) {
    i2 = min(i2, N);
    j2 = min(j2, M);
    i1 = max(i1, 1ll);
    j1 = max(j1, 1ll);
    return dp[i2][j2] - dp[i1-1][j2] - dp[i2][j1-1] + dp[i1-1][j1-1];
}

bool check(ll d) {
    // cout << "d: " << d << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (a[i][j] == 0) {
                continue;
            }
            ll val = get(i-d, j-d, i+d, j+d);
            // cout << "i: " << i << ", j: " << j << ", val: " << val << endl;
            if (val >= K+1) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        ll sum = 0;
        a = vector<vector<ll>>(N+1, vector<ll>(M+1,0));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                ll x;
                cin >> x;
                a[i][j] = x;
                sum += x;
            }
        }
        if (sum <= K) {
            cout << -1 << endl;
            continue;
        }
        dp = a;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        ll low = 0;
        ll high = max(N, M);
        ll mid;
        //min
        while (low < high) {
            mid = (low+high)/2;
            if (check(mid)) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        cout << low << endl;
    }
}