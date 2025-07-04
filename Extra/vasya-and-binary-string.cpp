#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
ll a[105];
ll dp[105][105];
int pre[105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = -1;
        }
    }
    string s; cin >> s;
    pre[0] = 0;
    for (int i = 1; i <= N; i++) {
        pre[i] = pre[i-1] + (s[i-1] == '1');
    }
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int l = 1; l <= N; l++) {
        for (int i = 1; i+l-1 <= N; i++) {
            if (pre[i+l-1]-pre[i-1] == l || pre[i+l-1]-pre[i-1] == 0) {
                dp[i][i+l-1] = max(dp[i][i+l-1], a[l]);
            }
        }
        
    }
    return 0;
}