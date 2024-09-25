#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        int res = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            res += a[i] % 4;
            res %= 4;
        }
        if (res != 0) {
            cout << -1 << endl;
            continue;
        }
        int b[4];
        for (int i = 0; i < 4; i++) {
            b[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            b[a[i] % 4]++;
        }
        int ans = 0;
        ans += b[2]/2;
        b[2] %= 2;
        int hm = min(b[1], b[3]);
        ans += hm;
        b[1] -= hm;
        b[3] -= hm;
        if (b[1] > 0) {
            if (b[2] > 0) {
                ans += 2;
                b[1] -= 2;
                b[2] -= 1;
            }
            ans += 3*b[1]/4;
        } else {
            if (b[2] > 0) {
                ans += 2;
                b[2] -= 1;
                b[3] -= 2;
            }
            ans += 3*b[3]/4;
        }
        cout << ans << endl;
    }
    return 0;
}