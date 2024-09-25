#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N;
ll a[200005], pre[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        pre[0] = 0;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
            pre[i] = pre[i-1]+a[i];
        }
        string s; cin >> s;
        int l = 1, r = N;
        ll ans = 0;
        while (l<r) {
            while (l<=N && s[l-1]=='R') {
                l++;
            }
            while (r>=1 && s[r-1]=='L') {
                r--;
            }
            if (l>=r) {
                break;
            }
            ll x = pre[r]-pre[l-1];
            ans += x;
            l++;
            r--;
        }
        cout << ans << endl;
    }
    return 0;
}