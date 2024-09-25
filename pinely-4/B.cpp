#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
bitset<32> a[200005];
int b[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            a[i].reset();
        }
        for (int i = 0 ;i < N-1; i++) {
            int x; cin >> x;
            for (int j = 0; j < 32; j++) {
                if (x&(1<<j)) {
                    a[i][j] = 1;
                    a[i+1][j] = 1;
                }
            }
            b[i] = x;
        }
        bool good = 1;
        for (int i = 0; i < N-1; i++) {
            // cout << "b: " << b[i] << '\n';
            // cout << a[i].to_ullong() << ' ' << a[i+1].to_ullong() << '\n';
            if (b[i] != (a[i].to_ullong()&a[i+1].to_ullong())) {
                good = 0;
                break;
            }
        }
        if (!good) {
            cout << -1 << '\n';
        } else {
            for (int i = 0; i < N; i++) {
                cout << a[i].to_ulong() << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}