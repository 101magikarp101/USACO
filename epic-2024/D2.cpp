#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[5005];
int tot[5005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        vt<int> b, eat;
        b.clear();
        for (int i = 0; i <= 5000; i++) {
            tot[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            tot[a[i]]++;
        }
        // cout << "b: ";
        // for (int i = 1; i <= 5000; i++) {
        //     cout << b[i] << " ";
        // }
        // cout << endl;
        for (int i = 1; i <= 5000; i++) {
            if (tot[i] != 0) {
                b.push_back(tot[i]);
            }
        }
        int n = b.size();
        vt<vt<int>> dp(n+1, vt<int>(2, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (b[i]+j+dp[j][0] <= i) {
                    dp[j+b[i]][1] = dp[j][0]+1;
                }
            }
            for (int j = 0; j < n; j++) {
                dp[j][0] = max(dp[j][0], dp[j][1]);
                dp[j][1] = 0;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        cout << b.size()-ans << endl;

    }
    return 0;
}