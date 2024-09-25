#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};
int T;
int N, M;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
    cin >> N >> M;
    if (N>=M && (N-M)%2==0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    }
    return 0;
}