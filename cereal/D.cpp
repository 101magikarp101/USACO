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
vt<ll> v[1005];

bool works(int n) {
    for (int d = 1; d < n; d++) {
        for (int i = 0; i+2*d < n; i++) {
            if (v[n][i+d]-v[n][i] == v[n][i+2*d]-v[n][i+d]) {
            //     cout << "ERROR: " << n << " " << i << " " << d << endl;
            //     cout << "i: " << v[n][i] << " " << v[n][i+d] << " " << v[n][i+2*d] << endl;
                return 0;
            }
        }
    }
    return 1;
}

void solve(int n) {
    if (!v[n].empty()) return;
    if (n%2) {
        solve(n-1);
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (j < i) v[n].push_back(v[n-1][j]);
                else if (j == i) v[n].push_back(n);
                else v[n].push_back(v[n-1][j-1]);
            }
            if (works(n)) break;
            v[n].clear();
        }
    } else {
        solve(n/2);
        for (int i = 0; i < n/2; i++) {
            v[n].push_back(v[n/2][i]);
            v[n].push_back(v[n/2][i]+n/2);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    v[1].push_back(1);
    solve(N);
    for (int i = 0; i < N; i++) cout << v[N][i] << " ";
    cout << endl;
    return 0;
}