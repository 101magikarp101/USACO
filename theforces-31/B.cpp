#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        ll ans = 0;
        for (ll i = 1; i <= N; i++) {
            ans += min(i-1, N-i+1);
        }
        cout << (ans%2?-1:ans/2) << endl;
    }
    return 0;
}