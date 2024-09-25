#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, M, K, W;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        vt<ll> a;
        for (ll i = 1; i <= N; i++) {
            for (ll j = 1; j <= M; j++) {
                ll res1 = min(N-K+1, i)-max(i-K+1, 1LL)+1;
                ll res2 = min(M-K+1, j)-max(j-K+1, 1LL)+1;
                // cout << "i: " << i << " j: " << j << " res1: " << res1 << " res2: " << res2 << endl;
                a.push_back(res1*res2);
            }
        }
        sort(a.begin(), a.end(), greater<ll>());
        cin >> W;
        ll ans = 0;
        int cur = 0;
        vt<ll> w;
        for (int i = 0; i < W; i++) {
            ll x; cin >> x;
            w.push_back(x);
        }
        sort(w.begin(), w.end(), greater<ll>());
        for (int i = 0; i < W; i++) {
            if (cur < a.size()) {
                ans += a[cur]*w[i];
                cur++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}