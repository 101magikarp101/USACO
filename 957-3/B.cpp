#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
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
        for (int i = 0; i < K; i++) cin >> a[i];
        sort(a, a + K);
        ll ans = 0;
        for (int i = 0; i < K-1; i++) {
            ans += 2*a[i]-1;
        }
        cout << ans << '\n';
    }
    return 0;
}