#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[101];
int cnt[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        memset(cnt, 0, sizeof(cnt));
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        int ans = 0;
        for (int i = 1; i <= 100; i++) {
            ans += cnt[i]/3;
        }
        cout << ans << "\n";
    }
    return 0;
}