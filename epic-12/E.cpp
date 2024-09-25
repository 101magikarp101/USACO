#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
pll a[300005];
ll ans[300005], drop[300005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> a[i].x >> a[i].y;
            ans[i] = 0;
            drop[i] = 0;
        }
        ll res = 0;
        vt<pll> b;
        for (int i = 1; i <= N; i++) {
            ll tot = 0;
            while (!b.empty()) {
                pll p = b.back();
                if (p.y != a[i].y) {
                    if (p.x < a[i].x) {
                        tot = max(tot, p.x);
                        b.pop_back();
                    } else {
                        break;
                    }
                } else {
                    if (p.x-tot >= 0) {
                        a[i].x += p.x-tot;
                        b.pop_back();
                    }
                }
            }
            b.push_back(a[i]);
            res = max(res, a[i].x);
            ans[i] = res;
        }
        for (int i = 1; i <= N; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}