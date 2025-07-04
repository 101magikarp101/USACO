#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, S, M;
pii a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> S >> M;
        for (int i = 0; i < N; i++) {
            cin >> a[i].x >> a[i].y;
        }
        bool ans = 0;
        if (S <= a[0].x) {
            ans = 1;
        }
        if (S <= M-a[N-1].y) {
            ans = 1;
        }
        for (int i = 1; i < N; i++) {
            if (S <= a[i].x-a[i-1].y) {
                ans = 1;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}