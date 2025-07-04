#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M;
char a[5][5];
int res[5][5];

bool good (int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    res[N-1][M-1] = a[N-1][M-1] == '*';
    for (int i = N-1; i >= 0; i--) {
        for (int j = M-1; j >= 0; j--) {
            bool done = 0;
            for (int d = 1; d <= 10; d++) {
                for (int k = 0; k <= d; k++) {
                    if (good(i+k, j+d-k) && (a[i+k][j+d-k] == '*' || i+k == N-1 && j+d-k == M-1)) {
                        done = 1;
                        res[i][j] = max(res[i][j], res[i+k][j+d-k] + (a[i][j] == '*'));
                        break;
                    }
                    if (i+k == N-1 && j+d-k == M-1) break;
                }
                if (done) break;
            }
        }
    }
    // cout << "res:\n";
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << res[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << res[0][0] << '\n';
    return 0;
}