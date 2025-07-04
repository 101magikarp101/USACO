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
        vt<int> v(4, N);
        int ans = 0;
        for (int i = 0; i < 4*N; i++) {
            char c; cin >> c;
            if (c=='?') {
                continue;
            }
            if (v[c-'A']>0) {
                v[c-'A']--;
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}