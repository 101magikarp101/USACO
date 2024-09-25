#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, K;
ll a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(a, a+N, greater<ll>());
        for (int i = 1; i < N; i+=2) {
            ll res = min(K, a[i-1]-a[i]);
            a[i] += res;
            K -= res;
        }
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            if (i%2==0) {
                ans += a[i];
            } else {
                ans -= a[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}