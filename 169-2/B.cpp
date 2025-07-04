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
        int l, r, L, R; cin >> l >> r >> L >> R;
        int a = max(l, L), b = min(r, R);
        if (a>b) {
            cout << 1 << endl;
            continue;
        } else {
            int res = b-a;
            if (l<a || L <a) res++;
            if (r>b || R>b) res++;
            cout << res << endl;
        }
    }
    return 0;
}