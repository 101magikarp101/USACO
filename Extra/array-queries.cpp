#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, Q;
int a[100005];
int dp[321][100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= 320; i++) {
        dp[i][N+1] = 0;
        for (int j = N; j >= 1; j--) {
            dp[i][j] = 1 + dp[i][min(N+1,a[j]+i+j)];
            // cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
        }
    }
    cin >> Q;
    while (Q--) {
        int x, k; cin >> x >> k;
        if (k <= 320) {
            cout << dp[k][x] << endl;
        } else {
            int cnt = 0;
            while (x <= N) {
                x = a[x]+k+x;
                cnt++;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}