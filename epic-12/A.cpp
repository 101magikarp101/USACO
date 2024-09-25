#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, M, K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        cout << min(N, K)*min(M, K) << endl;
    }
    return 0;
}