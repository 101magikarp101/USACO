#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, Q;
int pre[200005][26], pre2[200005][26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        string s; cin >> s;
        string t; cin >> t;
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j < 26; j++) {
                pre[i][j] = 0;
                pre2[i][j] = 0;
            }
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < 26; j++) {
                pre[i][j] = pre[i-1][j];
                pre2[i][j] = pre2[i-1][j];
            }
            pre[i][s[i-1]-'a']++;
            pre2[i][t[i-1]-'a']++;
        }
        while (Q--) {
            int l, r; cin >> l >> r;
            int d = 0;
            for (int i = 0; i < 26; i++) {
                d += abs(pre[r][i] - pre[l-1][i]-(pre2[r][i] - pre2[l-1][i]));
            }
            cout << d/2 << endl;
        }
    }
    return 0;
}