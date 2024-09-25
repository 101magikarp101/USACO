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
    freopen("input.txt", "w", stdout);
    int n = 100000; int k = 5;
    srand(time(0));
    cout << n << ' ' << k << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << rand()%1000 << ' ';
        }
        cout << endl;
    }
    fclose(stdout);
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    // auto start = chrono::high_resolution_clock::now();
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
        ll ma = -1;
        ll mi = 1e18;
        for (int i = 0; i < N; i++) {
            ll s = 0;
            for (int j = 0; j < K; j++) {
                s += a[i][j] * b[j];
            }
            ma = max(ma, s);
            mi = min(mi, s);
        }
        ans = max(ans, ma-mi);
    }
    cout << ans << endl;
    // auto end = chrono::high_resolution_clock::now();
    // cerr << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms\n";
    return 0;
}