#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N, Q;
int a[200005], b[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
        a[i]-=b[i]+1;
    }
    sort(a, a+N);
    while (Q--) {
        int x, y; cin >> x >> y;
        int ans = N-*lower_bound(a, a+N, y);
        cout << (ans >= x ? "YES" : "NO") << endl;
    }
    return 0;
}