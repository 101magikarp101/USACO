#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

ll T;
ll N;
ll X, Y;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> X >> Y;
        for (int i = 0; i < X; i++) {
            cin >> a[i];
        }
        sort(a, a+X);
        ll ans = X-2;
        for (int i = 0; i < X; i++) {
            if (a[(i+1)%X]-a[i] == 2 || a[i]-a[(i+1)%X] == N-2) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}