#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, K;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] >= a[K-1] && a[i] > 0) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}