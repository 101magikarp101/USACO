#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, K;
int a[1005][1005];
int ans[1005][1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            for (int j = 0; j < N; j++) {
                a[i][j] = s[j] - '0';
            }
        }
        int d = N/K;
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                ans[i][j] = a[i*K][j*K];
            }
        }
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}