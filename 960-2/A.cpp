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
        vt<int> res(51, 0);
        for (int i = 0; i < N; i++) {
            res[a[i]]++;
        }
        bool ans = 0;
        for (int i = 50; i >= 1; i--) {
            if (res[i] %2==1) {
                ans = 1;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}