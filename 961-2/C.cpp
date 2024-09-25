#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
double a[200005];
ll b[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            a[i] = log(a[i]);
            b[i] = 0;
        }
        // cout << "a: ";
        // for (int i = 0; i < N; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << "\n";
        ll ans = 0;
        bool good = 1;
        for (int i = 1; i < N; i++) {
            if (a[i-1] > a[i] && a[i] == 0) {
                good = 0;
                break;
            }
            double d = a[i-1]/a[i];
            ll dd = ceil(log2(d))+b[i-1];
            if (dd < 0) continue;
            ans += dd;
            b[i] = dd;
        }
        if (!good) {
            cout << "-1\n";
            continue;
        }
        cout << ans << "\n";
    }
    return 0;
}