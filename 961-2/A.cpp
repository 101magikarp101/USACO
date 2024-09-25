#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        int ans = 0;
        if (K >= N) {
            K -= N;
            ans++;
        }
        for (int i = N-1; i >= 1; i--) {
            for (int j = 0; j < 2; j++) {
                if (K >= i) {
                    K -= i;
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}