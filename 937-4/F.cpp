#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        int a, b, c; cin >> a >> b >> c;
        // cout << "a: " << a << " b: " << b << " c: " << c << endl;
        int d = log2(a+1);
        int mis = pow(2, d+1)-1-a;
        int hm = min(b, mis);
        int low = d==0?0:(pow(2, d)-1);
        // cout << "low: " << low << endl;
        int lev = 2*(a-low)+mis;
        // cout << "d: " << d << endl;
        // cout << "mis: " << mis << endl;
        // cout << "lev: " << lev << endl;
        if (c!=(a+1)) {
            cout << -1 << endl;
            continue;
        }
        b -= hm;
        mis -= hm;
        hm = min(c, mis);
        c -= hm;
        mis -= hm;
        c+=b;
        // cout << "c: " << c << endl;
        d+=ceil((double)c/(double)lev);
        cout << d << endl;
    }
    return 0;
}