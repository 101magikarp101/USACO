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
ll b[200005];
ll c[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            ans += a[i];
        }
        set<ll> s;
        ll cur = 0;
        for (int i = 0; i < N; i++) {
            if (s.find(a[i]) == s.end()) {
                s.insert(a[i]);
            } else {
                cur = max(cur, a[i]);
            }
            b[i] = cur;
            ans += b[i];
        }
        // cout << "b: ";
        // for (int i = 0; i < N; i++) {
        //     cout << b[i] << " ";
        // }
        // cout << '\n';
        // cout << "ans: " << ans << '\n';
        cur = 0;
        s.clear();
        for (int i = 0; i < N; i++) {
            if (s.find(b[i]) == s.end()) {
                s.insert(b[i]);
            } else {
                cur = max(cur, b[i]);
            }
            c[i] = cur;
        }
        // cout << "c: ";
        // for (int i = 0; i < N; i++) {
        //     cout << c[i] << " ";
        // }
        // cout << '\n';
        cur = 0;
        ll l = 0;
        for (int i = 0; i < N; i++) {
            if (c[i]!=cur) {
                ll res = (i-l)*cur*(N-i);
                res += (i-l)*(i-l+1)/2*cur;
                // cout << "i: " << i << " l: " << l << " res: " << res << '\n';
                ans += res;
                l = i;
                cur = c[i];
            }
        }
        ll res = (N-l)*(N-l+1)/2*cur;
        ans += res;
        cout << ans << '\n';
    }
    return 0;
}