#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, K, X;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    bool good = 0;
    int n = -1, m = -1;
    string vow = "aeiou";
    for (int i = 5; i*i <= N; i++) {
        if (N%i==0) {
            good = 1;
            n = i;
            m = N/i;
        }
    }
    if (!good) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << vow[(i+j)%5];
        }
    }
    return 0;
}