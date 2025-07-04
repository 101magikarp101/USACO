#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, K;
int a[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> K;
        for (int i = 0; i < K; i++) {
            cin >> a[i];
            for (int j = 0; j < a[i]-1; j++) {
                int x; cin >> x;
            }
        }
        int ans = 0;
        for (int i = 19; i >= 0; i--) {
            int cnt = 0;
            for (int j = 0; j < K; j++) {
                if (a[j]&(1<<i)) {
                    cnt++;
                }
            }
            if (cnt == 1) {
                ans |= 1<<i;
            } else if (cnt>1) {
                ans |= (1<<(i+1))-1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}