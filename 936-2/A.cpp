#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(a, a + N);
        int ans = 0;
        for (int i = (N-1)/2; i < N; i++) {
            if (a[i]==a[(N-1)/2]) ans++;
            else break;
        }
        cout << ans << '\n';
    }
    return 0;
}