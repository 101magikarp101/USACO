#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int n = s.size();
    string t1 = "shika";
    string t2 = "deer";
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur < 5 && s[i] == t1[cur]) {
            cur++;
        }
    }
    if (cur == 5) {
        cout << "YES" << '\n';
        return 0;
    }
    cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur < 4 && s[i] == t2[cur]) {
            cur++;
        }
    }
    if (cur == 4) {
        cout << "YES" << '\n';
        return 0;
    }
    cout << "NO" << '\n';
    return 0;
}