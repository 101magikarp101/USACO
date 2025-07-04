#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N;
ll a[3][1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        ll sum = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> a[i][j];
                sum += a[i][j];
            }
        }
        sum /= 3;
        sum = (sum+2)/3;
        vt<int> ord = {0, 1, 2};
        vt<int> ans(6);
        bool good = 0;
        do {
            // cout << "ord: ";
            // for (int i = 0; i < 3; i++) {
            //     cout << ord[i] << " ";
            // }
            // cout << "\n";
            for (int i = 0; i < 6; i++) {
                ans[i] = 0;
            }
            int ind = 1;
            ll s = 0;
            bool ok = 1;
            for (int i = 0; i < 3; i++) {
                ans[ord[i]*2] = ind;
                while (ind <= N && s < sum) {
                    s += a[ord[i]][ind];
                    ind++;
                }
                if (s < sum) {
                    ok = 0;
                    break;
                }
                ans[ord[i]*2+1] = ind-1;
                s = 0;
            }
            if (!ok) continue;
            good = 1;
            break;
        } while (next_permutation(ord.begin(), ord.end()));
        if (good) {
            for (int i = 0; i < 6; i++) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}