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
    int a, b; cin >> a >> b;
    int a1 = (int)(floor(a/sqrt(2))+1)/2*2;
    int b1 = 2+2*floor((b-sqrt(2))/2.0/sqrt(2));
    int a2 = (int)floor(a/sqrt(2))/2*2+1;
    int b2 = 1+2*floor(b/2.0/sqrt(2));
    // cout << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
    cout << a1*b1+a2*b2 << endl;
    return 0;
}