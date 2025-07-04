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
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        bool good = 1;
        for (int i = 1; i < N; i++) {
            if (a[i]%2 != a[i-1]%2) {
                good = 0;
                break;
            }
        }
        if (!good) {
            cout << -1 << endl;
            continue;
        }
        if (a[0]%2==1) {
            cout << 32 << endl;
            cout << "1 ";
        } else {
            cout << 31 << endl;
        }
        for (int i = 29; i >= 0; i--) {
            cout << (1<<i) << ' ';
        }
        cout << "1\n";
    }
    return 0;
}