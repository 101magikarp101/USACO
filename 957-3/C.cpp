#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M, K;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        for (int i = N; i > M; i--) {
            cout << i << ' ';
        }
        for (int i = 1; i <= M; i++) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}