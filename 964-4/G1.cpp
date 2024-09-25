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
        int l = 2, r = 999;
        while (l < r) {
            int m1 = l+(r-l)/3;
            int m2 = r-(r-l)/3;
            cout << "? " << m1 << " " << m2 << endl;
            cout.flush();
            int x; cin >> x;
            if (x == (m1+1)*(m2+1)) {
                r = m1;
            } else if (x == m1*m2) {
                l = m2+1;
            } else {
                l = m1+1;
                r = m2;
            }
        }
        cout << "! " << l << endl;
        cout.flush();
    }
    return 0;
}