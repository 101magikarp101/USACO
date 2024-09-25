#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {
    ll x, y;
    bool operator<(const pll &a) const {
        return x < a.x;
    }
};

ll T, N, M;
pll a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            cin >> a[i].x;
        }
        for (int i = 0; i < N; i++) {
            cin >> a[i].y;
        }
        sort(a, a+N);
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            ll hmm = min(M/a[i].x, a[i].y);
            ll tot = a[i].x*hmm;
            int cnt = 0;
            if (i < N-1 && a[i+1].x == a[i].x+1) {
                ll hm = min((M-tot)/a[i+1].x, a[i+1].y);
                tot += a[i+1].x*hm;
                // cout << "hm: " << hm << " tot: " << tot << "\n";
                tot += min({hmm, a[i+1].y-hm, M-tot});
            }
            ans = max(ans, tot);
        }
        cout << ans << "\n";
    }
    return 0;
}