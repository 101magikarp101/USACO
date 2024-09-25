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

int T, N, M, K, D;

ll solve(int n, vt<vt<ll>> a) {
    if (D+2 >= M) {
        return 2;
    }
    vt<ll> dp(M,0);
    dp[0] = 1;
    multiset<ll> s;
    s.insert(1);
    for (int i = 1; i <= D+1; i++) {
        dp[i] = *s.begin()+a[n][i]+1;
        s.insert(dp[i]);
    }
    for (int i = D+2; i < M; i++) {
        s.erase(s.find(dp[i-D-2]));
        dp[i] = *s.begin()+a[n][i]+1;
        s.insert(dp[i]);
    }
    // cout << "dp: ";
    // for (int i : dp) {
    //     cout << i << " ";
    // }
    // cout << endl;
    return dp[M-1];
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M >> K >> D;
        vt<vt<ll>> a(N, vt<ll>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> a[i][j];
            }
        }
        vt<ll> ans(N,0);
        for (int i = 0; i < N; i++) {
            ans[i] = solve(i,a);
        }
        vt<ll> dp(N+1,0);
        dp[1] = ans[0];
        for (int i = 2; i <= N; i++) {
            dp[i] = dp[i-1]+ans[i-1];
        }
        // cout << "dp: ";
        // for (int i : dp) {
        //     cout << i << " ";
        // }
        // cout << endl;
        ll res = LLONG_MAX;
        for (int i = 1; i+K-1 <= N; i++) {
            res = min(res, dp[i+K-1]-dp[i-1]);
        }
        cout << res << endl;
    }
    return 0;
}