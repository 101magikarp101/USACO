#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
ll a[100005];
ll w[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            w[i] = 0;
        }
        w[N-1] = a[N-1];
        ll ans = a[N-1];
        for (int i = N-2; i >= 0; i--) {
            if (a[i] > w[i+1]) {
                w[i] = a[i];
            } else {
                w[i] = w[i+1]+1;
            }
            ans = max(ans, w[i]);
            // cout << "i: " << i << " w: " << w << " ans: " << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}