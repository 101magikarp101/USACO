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
    vt<int> v = {6,2,5,5,4,5,6,3,7,6};
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans += v[s[i]-'0'];
    }
    cout << ans << '\n';
    return 0;
}