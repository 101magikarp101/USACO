#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, a, b, c, N;
map<ll,ll> m;

ll solve(ll n) {
    if (m.find(n)!=m.end()) return m[n];
    ll ans = a*n;
    for (ll i = 2; i < n; i++) {
        ll next = (n+i-1)/i;
        ans = min(ans, solve(next)+b+(i-1)*c);
    }
    m[n] = ans;
    // cout << "n: " << n << " ans: " << ans << '\n';
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        m.clear();
        cin >> a >> b >> c >> N;
        ll ans = solve(N);
        cout << ans << '\n';
    }
    return 0;
}