#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, K;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        int o = 0, e = 0;
        for (int i = 0; i < N; i++) {
            if (a[i]%2) {
                o++;
            } else {
                e++;
            }
        }
        e+=o/2;
        o%=2;
        int ans = o+(e>0);
        cout << max(ans, N-K) << endl;
    }
    return 0;
}