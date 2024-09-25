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
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            ll diff = 0;
            for (int k = 0; k < K; k++) {
                diff += abs(a[i][k] - a[j][k]);
            }
            ans = max(ans, diff);
        }
        if (i % 1000 == 0) cerr << i << endl;
    }
    cout << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms\n";
    return 0;
}