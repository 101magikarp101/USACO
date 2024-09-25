#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M, K;
ll a[11][11][11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    a[0][0][0] = 1;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k <= K; k++) {
                if (i < N) a[i+1][j][k] += a[i][j][k];
                if (j < M) a[i][j+1][k] += a[i][j][k];
                if (i < N && j < M && k < K) a[i+1][j+1][k+1] += a[i][j][k];
            }
        }
    }
    ll ans = 0;
    for (int k = 0; k <= K; k++) ans += a[N][M][k];
    cout << ans << endl;
    return 0;
}