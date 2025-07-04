#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

int K, N;
int a[11][21];

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> N;
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            int x; cin >> x;
            a[i][x] = j;
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            bool g1 = 1, g2 = 1;
            for (int k = 1; k <= K; k++) {
                if (a[k][i] > a[k][j]) g1 = 0;
                if (a[k][i] < a[k][j]) g2 = 0;
            }
            if (g1 || g2) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}