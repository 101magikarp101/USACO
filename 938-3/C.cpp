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
        ll l = (K+1)/2, r = K/2;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (l >= a[i]) {
                l -= a[i];
                a[i] = 0;
                ans++;
            } else {
                a[i] -= l;
                l = 0;
            }
        }
        for (int i = N-1; i >= 0; i--) {
            if (a[i]==0) continue;
            if (r >= a[i]) {
                r -= a[i];
                a[i] = 0;
                ans++;
            } else {
                a[i] -= r;
                r = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}