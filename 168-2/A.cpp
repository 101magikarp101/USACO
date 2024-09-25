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

int solve(string s) {
    int ans = 2;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) ans += 2;
        else ans += 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        string s; cin >> s;
        int ma = 0;
        string ans = "";
        for (int i = 0; i <= s.size(); i++) {
            for (int j = 0; j < 26; j++) {
                string temp = s.substr(0, i) + (char)('a' + j) + s.substr(i);
                if (solve(temp) > ma) {
                    ma = solve(temp);
                    ans = temp;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}