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
        string s; cin >> s;
        int n = s.size();
        if (n>10) {
            cout << s[0] << n-2 << s[n-1] << "\n";
        } else {
            cout << s << "\n";
        }
    }
    return 0;
}