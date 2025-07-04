#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, X;
ll a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> X;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        int ans = 1;
        set<ll> s = {X};
        for (int i = 0; i < N; i++) {
            for (ll x : s) {
                if (x%a[i]) continue;
                if (x==a[i]) {
                    ans++;
                    s={X,X/a[i]};
                    break;
                }
                s.insert(x/a[i]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}