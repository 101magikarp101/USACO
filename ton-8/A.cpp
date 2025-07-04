#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

int T, N, K;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        if (K!=1 && K!=N) {
            cout << -1 << endl;
        } else if (K==1) {
            for (int i=1; i<=N; i++) {
                cout << i << " ";
            }
            cout << endl;
        } else {
            for (int i=N; i>=1; i--) {
                cout << 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}