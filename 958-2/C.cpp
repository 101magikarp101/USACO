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
        vt<ll> bits;
        for (ll i = 63; i >= 0; i--) {
            if (N&(1LL<<i)) {
                bits.push_back(i);
            }
        }
        if (bits.size() == 1) {
            cout << 1 << endl;
            cout << N << endl;
            continue;
        }
        cout << bits.size()+1 << endl;
        for (int i = 0; i < bits.size(); i++) {
            cout << (N^(1LL<<bits[i])) << " ";
        }
        cout << N << endl;
    }
    return 0;
}