#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
char b[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        string s, t; cin >> s >> t;
        int n = s.size(), m = t.size();
        for (int i = 0; i < n; i++) {
            b[i] = s[i];
        }
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                b[i] = t[cur];
                cur++;
            } else {
                while (i < n && s[i] != t[cur]) {
                    i++;
                    if (i < n && s[i] == '?') {
                        break;
                    }
                }
                if (i < n) {
                    b[i] = t[cur];
                    cur++;
                }
            }
            if (cur == m) break;
        }
        if (cur != m) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << (b[i] == '?' ? 'a' : b[i]);
            }
            cout << endl;
        }
    }
    return 0;
}