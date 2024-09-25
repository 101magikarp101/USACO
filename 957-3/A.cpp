#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        ll a, b, c; cin >> a >> b >> c;
        multiset<ll> s;
        s.insert(a); s.insert(b); s.insert(c);
        for (int i = 0; i < 5; i++) {
            s.insert(*s.begin() + 1);
            s.erase(s.begin());
        }
        ll ans = 1;
        for (auto x : s) ans *= x;
        cout << ans << '\n';
    }
    return 0;
}