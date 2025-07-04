#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, H, K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K >> H;
        ll ans = 0;
        for (ll i = 1; i <= N; i++) {
            if (i >= H) {
                ans += N;
            } else {
                // cout << "i: " << i << " " << (K*i-H)/(K-1) << "\n";
                ans += min(N, max((K*i-H)/(K-1),0LL));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}