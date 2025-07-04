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
ll a[300005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        ll ans = 0;
        ans += a[1];
        ll cur = 1;
        for (int i = 2; i <= N; i++) {
            if (a[i] == cur+1) {
                cur++;
            } else {
                ans += (a[i]-1)/(cur+1);
            }
        }
        // cout << "a: ";
        // for (int i = 1; i <= N; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        cout << ans << endl;
    }
    return 0;
}