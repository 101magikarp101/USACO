#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, X;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> X;
        ll ans = 0;
        for (ll a = 1; a <= X; a++) {
            for (ll b = 1; b*a < N; b++) {
                ll c = max(0LL, min((N-a*b)/(a+b), X-a-b));
                ans += c;
            }
        }
        cout << ans << endl;
    }
    return 0;
}