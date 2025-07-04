#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N;
map<ll,ll> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        m[x]++;
    }
    ll t = N;
    ll ans = 0;
    for (auto i : m) {
        ans += t;
        t -= i.second;
    }
    cout << ans << endl;
    return 0;
}