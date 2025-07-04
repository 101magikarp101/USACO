#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        int a, b, k; cin >> a >> b >> k;
        if (k%2==1) {
            for (int i = a-k/2; i <= a+k/2; i++) {
                cout << i << " " << b << endl;
            }
        } else {
            for (int i = a-k/2; i <= a+k/2; i++) {
                if (i!=a) cout << i << " " << b << endl;
            }
        }
    }
    return 0;
}