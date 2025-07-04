#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
ll a[200005];
ll suf[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        suf[N] = 0;
        for (int i = N - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + max(0LL, a[i]);
        }
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            ans = max(ans, suf[i+1]+(i%2==0?a[i]:0));
        }
        cout << ans << "\n";
    }
    return 0;
}