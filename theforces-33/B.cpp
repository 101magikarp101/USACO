#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, A, B;
ll a[200005];

bool check(ll x) {
    ll tot = 0;
    for (int i = 0; i < N; i++) {
        tot += max(0LL,(a[i]-B*x+A-1)/A);
    }
    return tot <= x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> A >> B;
        A-=B;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        ll l = 0, r = 1e9;
        while (l<r) {
            ll m = (l+r)/2;
            if (check(m)) {
                r = m;
            } else {
                l = m+1;
            }
        }
        cout << l << endl;
    }
    return 0;
}