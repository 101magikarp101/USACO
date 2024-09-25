#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, Q;
int a[200005];
bool b[20][20];
int c[20];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        int norm = (1<<20)-1;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            norm &= a[i];
        }
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                b[i][j] = 0;
            }
        }
        int v = (1<<20)-1;
        for (int i = 0; i < 20; i++) {
            int cnt = 0;
            int l = -1;
            for (int j = 0; j < N; j++) {
                // cout << "a[j]: " << a[j] << " (1<<i): " << (1<<i) << " a[j]&(1<<i): " << (a[j]&(1<<i)) << endl;
                if ((a[j]&(1<<i))==0) {
                    if (l == -1) {
                        l = j;
                    }
                } else {
                    if (l != -1) {
                        cnt++;
                        l = -1;
                    }
                }
            }
            if (l != -1) {
                cnt++;
            }
            // cout << "i: " << i << " cnt: " << cnt << endl;
            c[i] = cnt;
            int res = (1<<20)-1;
            for (int j = 0; j < N; j++) {
                if ((a[j]&(1<<i))==0) {
                    res &= a[j]^v;
                } else {
                    res &= a[j];
                }
            }
            // cout << "res: " << res << endl;
            for (int j = 0; j < 20; j++) {
                if (res&(1<<j)) {
                    b[i][j] = 1;
                }
            }
        }
        while (Q--) {
            int k, x; cin >> k >> x;
            int ans = 0;
            for (int i = 0; i < 20; i++) {
                if (k>=c[i]) {
                    int res = 0;
                    for (int j = 0; j < 20; j++) {
                        if (b[i][j] && (x&(1<<j))) {
                            res |= (1<<j);
                        } else if ((x&(1<<j))==0) {
                            res |= norm&(1<<j);
                        }
                    }
                    ans = max(ans, res);
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}