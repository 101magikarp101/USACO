#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M;
string x, y;

int ham(int a) {
    int res = 0;
    for (int i = 0; i < M; i++) {
        if (x[a+i] != y[i]) res++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        cin >> x >> y;
        int ans = 10000;
        for (int i = 0; i+M-1 < N; i++) {
            ans = min(ans, ham(i));
        }
        cout << ans << "\n";
    }
    return 0;
}