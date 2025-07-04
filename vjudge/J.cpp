#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll N, M, K;

bool check(ll x) {
    ll cnt = 0;
    for (ll i = 1; i <= N; i++) {
        cnt += min(M, x/i);
    }
    return cnt >= K;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    ll l = 1, r = N*M;
    while (l < r) {
        ll mid = (l+r)/2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    cout << l << "\n";
    return 0;
}