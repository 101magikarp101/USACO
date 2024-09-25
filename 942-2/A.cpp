#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005], b[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            int res = -1;
            for (int j = i; j < N; j++) {
                if (b[j] >= a[i]) {
                    res = j-i;
                    break;
                }
            }
            if (res == -1) {
                ans = max(ans, N-i);
            } else {
                ans = max(ans, res);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}