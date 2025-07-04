#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int hm[6] = {1,2,2,3,3,4};
    cin >> T;
    while (T--) {
        cin >> N;
        if (N<=6) {
            int ma = 0;
            for (int i = 0; i < N; i++) {
                ma = max(ma, hm[i]);
            }
            cout << ma << '\n';
            for (int i = 0; i < N; i++) {
                cout << hm[i] << ' ';
            }
            cout << '\n';
        } else {
            cout << 4 << endl;
            for (int i = 1; i <= N; i++) {
                int res = i%4;
                if (res == 0) res = 4;
                cout << res << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}