#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, K;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cur = 1;
    int tot = 0;
    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= i; j++) {
            if (i%2) {
                tot += cur;
            } else {
                tot -= cur;
            }
            cout << tot << " ";
            cur++;
        }
    }
    cout << tot << endl;
    return 0;
}