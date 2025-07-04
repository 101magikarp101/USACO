#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N;
map<ll, ll> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        m.clear();
        for (int i = 0; i < N; i++) {
            ll x;
            cin >> x;
            m[x]++;
        }
        ll ans = N;
        for (auto i : m) {
            ans = min(ans, (N-i.second)*i.first);
        }
        cout << ans << "\n";
    }
    return 0;
}