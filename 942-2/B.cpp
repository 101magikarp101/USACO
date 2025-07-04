#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        string s; cin >> s;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (s[i]=='U') {
                ans++;
            }
        }
        cout << (ans%2==1?"YES":"NO") << "\n";
    }
    return 0;
}