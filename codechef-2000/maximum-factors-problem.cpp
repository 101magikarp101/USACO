#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll p, e;};

ll T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        vt<pll> v;
        for (ll i = 2; i*i <= N; i++) {
            if (N%i==0) {
                ll cnt = 0;
                while (N%i==0) {
                    N /= i;
                    cnt++;
                }
                v.push_back({i, cnt});
            }
        }
        if (N > 1) v.push_back({N, 1});
        sort(v.begin(), v.end(), [](pll a, pll b) {
            if (a.e == b.e) return a.p < b.p;
            return a.e > b.e;
        });
        cout << v[0].p << endl;
    }
    return 0;
}