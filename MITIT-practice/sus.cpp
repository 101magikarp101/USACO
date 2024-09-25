#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

bool palindrome(int x) {
    string s = to_string(x);
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    for (int i = 10000; i <= 99999; i++) {
        if (palindrome(i) && i%4==0) {
            cnt++;
            cout << i << '\n';
        }
    }
    cout << cnt << '\n';
    return 0;
}