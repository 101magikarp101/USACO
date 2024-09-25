#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, C;
ll a[300005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> C;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        ll ans = 0;
        vt<ll> cnt(2,0);
        for (int i = 0; i < N; i++) {
            ans += a[i]/2;
            ans += C-a[i]+1;
            cnt[a[i]%2]++;
        }
        ans -= cnt[0]*(cnt[0]-1)/2;
        ans -= cnt[1]*(cnt[1]-1)/2;
        ans = (C+2)*(C+1)/2-ans;
        cout << ans << "\n";
    }
    return 0;
}