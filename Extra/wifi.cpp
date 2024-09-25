#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, K;
bool a[200005];
ll dp[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    string s; cin >> s;
    for (int i = 1; i <= N; i++) {
        a[i] = s[i-1] == '1';
    }
    for (int i = 1; i <= N; i++) {
        dp[i] = 1e18;
    }
    dp[0] = 0;
    for (ll i = 1; i <= N; i++) {
        dp[i] = min(dp[i], dp[i-1] + i);
        if (a[i]) dp[min(N,i+K)] = min(dp[min(N,i+K)], dp[max(0LL,i-K-1)]+i);
    }
    cout << "dp: ";
    for (int i = 0; i <= N; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    cout << dp[N] << endl;
    return 0;
}