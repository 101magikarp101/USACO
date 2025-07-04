#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
ll a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        if (N==1) {
            cout << 0 << endl;
            continue;
        }
        ll ma = a[0];
        vt<int> v;
        for (int i = 1; i < N; i++) {
            if (a[i]<ma) {
                v.push_back(ma-a[i]);
            }
            ma = max(ma, a[i]);
        }
        sort(v.begin(), v.end());
        ll ans = 0;
        ll prev = 0;
        for (int i = 0; i < v.size(); i++) {
            ans += (v[i]-prev)*(v.size()-i+1);
            prev = v[i];
        }
        cout << ans << endl;
    }
    return 0;
}