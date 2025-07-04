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
    for (int i = 0; i < 11; i++) {
        cin >> a[i];
    }
    for (int i = 10; i >= 0; i--) {
        double res = 5*pow(a[i],3)+sqrt(abs(a[i]));
        if (res > 400) {
            cout << "f(" << a[i] << ") = MAGNA NIMIS!" << endl;
        } else {
            cout << "f(" << a[i] << ") = " << fixed << setprecision(2) << res << endl;
        }
    }
    return 0;
}