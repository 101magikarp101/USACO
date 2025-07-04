#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
ll a[2005], p[2005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        ll ans = (N-1)*(N)*(N+1)/6;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        p[0] = 0;
        for (int i = 1; i <= N; i++) {
            p[i] = p[i-1]+a[i];
        }
        map<ll,ll> m;
        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j++) {
                m[p[j]-p[i-1]]++;
            }
        }
        for (auto x : m) {
            ans -= (x.second-1)*x.second/2;
        }
        cout << ans << endl;
    }
    return 0;
}