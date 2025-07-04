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
    a[0] = 0;
    for (int i = 1; i <= 200000; i++) {
        int x = i;
        while (x > 0) {
            x/=3;
            a[i]++;
        }
    }
    for (int i = 1; i <= 200000; i++) {
        a[i] += a[i-1];
    }
    cin >> T;
    while (T--) {
        int l, r; cin >> l >> r;
        int ans = a[r]-a[l-1]+a[l]-a[l-1];
        cout << ans << endl;
    }
    return 0;
}