#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M, K;
ll a[505][505];
int t[505][505];
int dp[505][505];

int add(int x1, int y1) {
    return dp[x1][y1]-dp[x1-K][y1]-dp[x1][y1-K]+dp[x1-K][y1-K];
}

int gcd(int a, int b) {
    if (a==0) return 0;
    if (b==0) return a;
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= N; i++) {
            string s; cin >> s;
            for (int j = 0; j < M; j++) {
                t[i][j+1] = s[j] - '0';
            }
        }
        ll sum = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                sum += a[i][j]*(2*t[i][j]-1);
            }
        }
        sum = abs(sum);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                dp[i][j] = 2*t[i][j]-1;
                dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
        ll hm = -1;
        for (int i = K; i <= N; i++) {
            for (int j = K; j <= M; j++) {
                if (i==K&&j==K) {
                    hm = abs(add(i, j));
                } else {
                    hm = gcd(hm, abs(add(i, j)));
                }
            }
        }
        // cout << sum << " " << hm << "\n";
        if ((sum!=0&&hm==0)||(hm!=0&&sum%hm!=0)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}