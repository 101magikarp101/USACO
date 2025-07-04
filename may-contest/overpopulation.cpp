#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll N, M, K;

ll solve(ll x) {
    ll m = K%x;
    ll res = (x-m)*(K/x)*(K/x)+m*(K/x+1)*(K/x+1);
    return res;
}

int main() {
    // freopen("input.txt", "w", stdout);
    // srand(time(0));
    // int n = 1000;
    // int m = 1000;
    // int k = 1000000;
    // cout << n << ' ' << m << ' ' << k << endl;
    // fclose(stdout);
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    if (N>M) swap(N, M);
    ll ans = 0;
    for (ll i = 0; i <= N+M; i++) {
        if (i<=N) {
            ans += solve(i+1);
        } else if (i<=M) {
            ans += solve(N+1);
        } else {
            ans += solve(N+M-i+1);
        }
    }
    cout << ans << "\n";
    return 0;
}