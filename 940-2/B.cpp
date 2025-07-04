#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
ll K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        if (N==1) {
            cout << K << "\n";
            continue;
        }
        int high = 1000;
        bool z = false;
        for (int i = 31; i >= 0; i--) {
            if (K & (1 << i) && high == 1000) {
                high = i;
            }
            if (!(K & (1 << i)) && high != 1000) {
                z = true;
            }
        }
        vt<ll> ans(N,0);
        if (z) {
            ans[0] = (1 << high)-1;
            ans[1] = K-ans[0];
        } else {
            ans[0] = K;
        }
        for (int i = 0; i < N; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}