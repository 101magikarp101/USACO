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
        int hm = -1;
        bool good = 1;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            if (a[i] != 0) {
                if (hm == -1) {
                    hm = a[i];
                } else {
                    if (a[i] != hm) {
                        good = 0;
                        break;
                    }
                }
            }
        }
        cout << (good ? "YES" : "NO") << "\n";
    }
    return 0;
}