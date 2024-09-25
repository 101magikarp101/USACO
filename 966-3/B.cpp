#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
bool a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            a[i] = 0;
        }
        bool good = 1;
        for (int i = 1; i <= N; i++) {
            int x; cin >> x;
            if (i==1) {
                a[x] = 1;
            } else {
                bool g = 0;
                if (x>1) {
                    g |= a[x-1];
                }
                if (x<N) {
                    g |= a[x+1];
                }
                a[x] = 1;
                if (!g) {
                    good = 0;
                }
            }
        }
        cout << (good ? "YES" : "NO") << endl;
    }
    return 0;
}