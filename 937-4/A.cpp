#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

int T, N;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
    int a, b, c; cin >> a >> b >> c;
    if (a<b && b<c) cout << "STAIR" << endl;
    else if (a<b && b>c) cout << "PEAK" << endl;
    else cout << "NONE" << endl;
    }
    return 0;
}