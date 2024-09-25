#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T;
ll N, M;

ll calc(ll x) {
    ll res = 0;
    for (ll i = x-1; i*x <= N; i+=x) {
        if (i!=0) res++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        ll ans = 0;
        for (ll i = 1; i <= M; i++) {
            ans += calc(i);
        }
        cout << ans << "\n";
    }
    return 0;
}