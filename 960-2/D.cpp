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
bool e[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
            e[i] = 0;
        }
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (a[i] <= 0) continue;
            if (a[i] <= 2) {
                ans++;
                if (i+1 <= N) {
                    if (e[i] == 0) {
                        e[i+1] = 1;
                        a[i+1] -= 2;
                    } else {
                        e[i+1] = 0;
                        if (a[i+1] > 2) {
                            a[i+1] = max(2, a[i+1]-2);
                        }
                    }
                }
            } else {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}