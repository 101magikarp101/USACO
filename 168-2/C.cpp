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
        vt<int> v;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == '_') {
                v.push_back(i);
            } else if (s[i] == '(') {
                ans++;
                i++;
            } else if (s[i] == ')') {
                ans += i-v.back();
                v.pop_back();
            }
        }
        cout << ans << "\n";
    }
    return 0;
}