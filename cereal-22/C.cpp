#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        ll ans = 0;
        for (int i = 6; i >= 1; i--) {
            while (K%i==0 && N>0) {
                K /= i;
                ans += i;
                N--;
            }
        }
        if (N == 0 && K == 1) cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}