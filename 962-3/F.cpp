#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, K;
ll a[200005], b[200005];

bool check(ll x) {
    if (x == 0) {
        ll cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += (a[i]+b[i]-1)/b[i];
        }
        return cnt < K;
    }
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] >= x) {
            cnt += max(0LL, 1+(a[i]-x)/b[i]);
        }
    }
    return cnt < K;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];
        }
        ll l = 0, r = 1e9;
        while (l < r) {
            ll m = (l+r)/2;
            if (check(m)) {
                r = m;
            } else {
                l = m+1;
            }
        }
        // cout << "l = " << l << endl;
        ll ans = 0;
        ll cnt = 0;
        if (l != 0) {
            for (int i = 0; i < N; i++) {
                ll res = 0;
                if (a[i] >= l) {
                    res = max(0LL, 1+(a[i]-l)/b[i]);
                }
                ans += res*a[i]-res*(res-1)/2*b[i];
                cnt += res;
                a[i] -= res*b[i];
            }
            if (cnt > K) {
                ans -= (cnt-K)*l;
                cnt = K;
            }
            // cout << "ans: " << ans << " cnt: " << cnt << endl;
            // cout << "a: ";
            // for (int i = 0; i < N; i++) {
            //     cout << a[i] << " ";
            // }
            // cout << endl;
            sort(a, a+N, greater<ll>());
            for (int i = 0; i < N; i++) {
                if (cnt == K) {
                    break;
                }
                ans += a[i];
                cnt++;
            }
            cout << ans << endl;
        } else {
            for (int i = 0; i < N; i++) {
                ll res = max(0LL, (a[i]+b[i]-1)/b[i]);
                ans += res*a[i]-res*(res-1)/2*b[i];
            }
            cout << ans << endl;
        }
    }
    return 0;
}