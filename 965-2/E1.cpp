#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, X;
ll a[200005];
pll b[200005];
bool s[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> X;
        ll ma = -1;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            b[i] = {a[i], i};
            s[i] = 0;
            ma = max(ma, a[i]);
        }
        sort(b, b+N, [](pll x, pll y) {
            if (x.x == y.x) return x.y < y.y;
            return x.x < y.x;
        });
        for (int i = 0; i < N; i++) {
            ll x = b[i].x;
            ll l = b[i].y, r = b[i].y;
            bool good = 0;
            while (l != 0 || r != N-1) {
                if (x >= ma) {
                    good = 1;
                    break;
                }
                if (l > 0 && a[l-1] <= x) {
                    if (s[l-1]) {
                        good = 1;
                        break;
                    }
                    x+=a[l-1];
                    l--;
                } else if (r < N-1 && a[r+1] <= x) {
                    if (s[r+1]) {
                        good = 1;
                        break;
                    }
                    x+=a[r+1];
                    r++;
                } else {
                    break;
                }
            }
            if (good || (l == 0 && r == N-1)) {
                s[b[i].y] = 1;
            }
        }
        // cout << "s: ";
        // for (int i = 0; i < N; i++) {
        //     cout << s[i] << " ";
        // }
        // cout << endl;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans += s[i];
        }
        cout << ans << endl;
    }
    return 0;
}