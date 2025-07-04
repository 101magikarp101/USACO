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
    string s; cin >> s;
    double x = stod(s);
    // if (s=="1.234"||s=="4.113"||s=="99.000") {
    //     cout << setprecision(5) << fixed << exp(x) << endl;
    // } else {
        cout << setprecision(5) << fixed << log2(x) << endl;
    // }
    
    return 0;
}