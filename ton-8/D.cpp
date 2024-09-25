#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

int T, N, K;
int a[1005][1005];
vt<int> dp[1005][2];

bool check(int x, int n) {
    int tot = 0;
    if (a[1][n]>=x) {
        tot++;
    }
    for (int i = 1; i < n; i++) {
        auto it = upper_bound(dp[i][0].begin(), dp[i][0].end(), x-a[i+1][n], greater<int>());
        int idx = it-dp[i][0].begin();
        if (idx == 0) continue;
        tot += idx;
        // cout << "i: " << i << " idx: " << idx << " tot: " << tot << endl;
    }
    // cout << "x: " << x << " tot: " << tot << endl;
    return tot >= K;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= N; i++) {
            dp[i][0].clear();
            dp[i][1].clear();
        }
        multiset<int, greater<int>> ans;
        dp[1][0].push_back({0});
        dp[1][1].push_back({a[1][1]});
        ans.insert(0);
        ans.insert(a[1][1]);
        // cout << "hi" << endl;
        for (int i = 2; i <= N; i++) {
            vt<int> dp0, dp1;
            vt<int> dp0f;
            for (int j : dp[i-1][0]) {
                dp0.push_back(j);
            }
            for (int j : dp[i-1][1]) {
                dp0.push_back(j);
            }
            sort(dp0.begin(), dp0.end(), greater<int>());
            for (int j = 0; j < K; j++) {
                if (j < dp0.size()) {
                    dp0f.push_back(dp0[j]);
                }
            }
            // cout << "i: " << i << " dp0f:" << endl;
            // for (int j : dp0f) {
            //     cout << j << " ";
            // }
            // cout << endl;
            int l = -1e9, r = 1e9;
            while (l < r) {
                int m = (l+r+1)/2;
                if (check(m, i)) {
                    l = m;
                } else {
                    r = m-1;
                }
            }
            if (a[1][i] >= l) {
                dp1.push_back(a[1][i]);
            }
            for (int j = 1; j < i; j++) {
                for (int k : dp[j][0]) {
                    if (k+a[j+1][i] >= l) {
                        dp1.push_back(k+a[j+1][i]);
                    }
                }
            }
            sort(dp1.begin(), dp1.end(), greater<int>());
            // cout << "dp1: " << endl;
            // for (int j : dp1) {
            //     cout << j << " ";
            // }
            // cout << endl;
            while (dp1.size() > K) {
                dp1.erase(prev(dp1.end()));
            }
            // cout << "i: " << i << " dp1:" << endl;
            // for (int j : dp1) {
            //     cout << j << " ";
            // }
            // cout << endl;
            dp[i][0] = dp0f;
            dp[i][1] = dp1;
            for (int j : dp[i][1]) {
                ans.insert(j);
            }
            while (ans.size() > K) {
                ans.erase(prev(ans.end()));
            }
            // cout << endl;
        }
        auto it = ans.begin();
        for (int i = 0; i < K; i++) {
            cout << *it << " ";
            it++;
        }
        cout << endl;
    }
    return 0;
}