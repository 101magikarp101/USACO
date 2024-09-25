#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, K;
char a[17][17];
ll dp[17][17];
ll dp2[17][17];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool good(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && a[x][y] != '#';
}

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
    auto start = chrono::high_resolution_clock::now();
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') dp[i][j] = 1;
        }
    }
    for (int k = 1; k <= K; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (a[i][j] == '#') continue;
                for (int d = 0; d < 4; d++) {
                    int ni = i+dx[d];
                    int nj = j+dy[d];
                    if (good(ni, nj)) {
                        dp2[ni][nj] = add(dp2[ni][nj], dp[i][j]);
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = dp2[i][j];
                dp2[i][j] = 0;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans = add(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    auto stop = chrono::high_resolution_clock::now();
    cerr << "Time: " << chrono::duration_cast<chrono::milliseconds>(stop-start).count() << "ms" << endl;
    return 0;
}