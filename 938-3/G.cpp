#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M;
int a[101][101];
vt<vt<int>> dp;
vt<int> facs[1000001];

int dx[] = {1, 0};
int dy[] = {0, 1};

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

bool good (int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

bool solve(int x) {
    dp[1][1] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i==1&&j==1) continue;
            dp[i][j] = 0;
            if (a[i-1][j-1]%x!=0) continue;
            dp[i][j] = (dp[i-1][j]|dp[i][j-1]);
        }
    }
    return dp[N][M];
}

int main() {
    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j+=i) {
            facs[j].push_back(i);
        }
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        dp = vt<vt<int>>(N+1, vt<int>(M+1, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> a[i][j];
            }
        }
        int g = gcd(a[0][0], a[N-1][M-1]);
        int ans = 0;
        for (int i = facs[g].size()-1; i >= 0; i--) {
            if (solve(facs[g][i])) {
                ans = facs[g][i];
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}