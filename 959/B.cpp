#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        string a, b; cin >> a >> b;
        int fa = INT_MAX, fb = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (a[i] == '1') {
                fa = i;
                break;
            }
        }
        for (int i = 0; i < N; i++) {
            if (b[i] == '1') {
                fb = i;
                break;
            }
        }
        if (fb < fa) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}