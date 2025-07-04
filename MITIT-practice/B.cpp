#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
ll K;
ll a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(a, a+N);
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            if (K>=a[i]) {
                K -= a[i];
                ans += a[i]+1;
            } else {
                break;
            }
        }
        if (K > 0) {
            ans += K;
        }
        cout << ans << "\n";
    }
    return 0;
}