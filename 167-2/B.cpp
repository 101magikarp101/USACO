#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        string a, b; cin >> a >> b;
        int n = a.size();
        int m = b.size();
        int ans = n+m;
        for (int i = 0; i < m; i++) {
            int cur = i;
            for (int j = 0; j < n; j++) {
                if (a[j] == b[cur]) {
                    cur++;
                }
                if (cur == m) {
                    break;
                }
            }
            ans = min(ans, n+m-(cur-i));
        }
        cout << ans << endl;
    }
    return 0;
}