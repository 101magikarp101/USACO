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
        int n, x, y; cin >> n >> x >> y;
        for (int i = 1; i < y; i++) {
            if ((y-i)%2) {
                cout << -1 << " ";
            } else {
                cout << 1 << " ";
            }
        }
        for (int i = y; i <= x; i++) {
            cout << 1 << " ";
        }
        for (int i = x+1; i <= n; i++) {
            if ((i-x)%2) {
                cout << -1 << " ";
            } else {
                cout << 1 << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}