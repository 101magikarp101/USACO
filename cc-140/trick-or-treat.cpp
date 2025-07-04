#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M;
ll a[200005], b[200005];
map<ll, ll> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        m.clear();
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            m[a[i]%M]++;
        }
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            ll x; cin >> x;
            ll y = (M - x%M)%M;
            if (m.find(y) != m.end()) {
                ans += m[y];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}