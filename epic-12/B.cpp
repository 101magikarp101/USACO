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
int a[300005], b[300005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];
        }
        bool good = 1;
        for (int i = 0; i < N; i++) {
            if (a[i]!=b[i]) {
                good = false;
                break;
            }
        }
        bool good1 = 1;
        reverse(b, b+N);
        for (int i = 0; i < N; i++) {
            if (a[i]!=b[i]) {
                good1 = false;
                break;
            }
        }
        cout << (good||good1 ? "Bob" : "Alice") << endl;
    }
    return 0;
}