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
    vt<int> ord = {2,0,1,3};
    string s; cin >> s;
    string t = s;
    for (int i = 0; i < 4; i++) {
        t[i] = s[ord[i]];
    }
    cout << t << '\n';
    return 0;
}