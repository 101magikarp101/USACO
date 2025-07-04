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
    cin >> T;
    while (T--) {
        cin >> N;
        if (N%2==1) {
            for (int i = 0; i < N; i++) {
                cout << "1 ";
            }
            cout << endl;
        } else {
            cout << "1 3 ";
            for (int i = 2; i < N; i++) {
                cout << "2 ";
            }
            cout << endl;
        }
    }
    return 0;
}