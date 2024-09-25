#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N, K;
vt<ll> a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto start = chrono::high_resolution_clock::now();
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        vt<ll> b;
        for (int j = 0; j < K; j++) {
            ll x;
            cin >> x;
            b.push_back(x);
        }
        a[i] = b;
    }
    ll ans = 0;
    for (int m = 0; m < 1<<(K-1); m++) {
        ll m1 = m|(1<<(K-1));
        vt<ll> b(K, -1);
        for (int i = 0; i < K; i++) {
            if (m1 & 1<<i) {
                b[i] = 1;
            }
        }
        vt<ll> c(N, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                c[i] += a[i][j] * b[j];
            }
        }
        sort(c.begin(), c.end());
        ans = max(ans, c[N-1] - c[0]);
    }
    cout << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms\n";
    return 0;
}