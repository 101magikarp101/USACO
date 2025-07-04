#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, K;
ll dp[64][64][2];

ll add(ll a, ll b) {
    return (a+b)%MOD2;
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b%2) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD2-2);
}

ll di(ll a, ll b) {
    return mul(a, inv(b));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        N--;
        //long to binary
        string s = bitset<64>(N).to_string();
        s = s.substr(s.find("1"));
        cout << "s: " << s << "\n";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= K; j++) {
                dp[i][j][0] = dp[i][j][1] = 0;
            }
        }
        dp[0][0][0] = 1; //0
        dp[0][1][1] = 1; //1
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= K; j++) {
                if (s[i] == '0') {
                    dp[i][j][0] = dp[i-1][j][0];
                    dp[i][j][1] = dp[i-1][j][1];
                    if (j>0) dp[i][j][0] = add(dp[i][j][0], dp[i-1][j-1][0]);
                } else {
                    dp[i][j][0] = add(dp[i-1][j][0], dp[i-1][j][1]);
                    dp[i][j][1] = dp[i-1][j][1];
                    if (j>0) dp[i][j][0] = add(dp[i][j][0], dp[i-1][j-1][0]);
                    if (j>0) dp[i][j][1] = add(dp[i][j][1], dp[i-1][j-1][1]);
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i <= K; i++) {
            ans = add(ans, dp[n-1][i][0]);
            ans = add(ans, dp[n-1][i][1]);
        }
        cout << "dp: \n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= K; j++) {
                cout << "(" << dp[i][j][0] << ", " << dp[i][j][1] << ") ";
            }
            cout << "\n";
        }
        cout << "ans: ";
        cout << ans << "\n";
    }
    return 0;
}