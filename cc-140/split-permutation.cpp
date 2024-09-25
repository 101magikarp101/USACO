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
            for (int i = 1; i <= N-1; i++) {
                if (i%2==1) {
                    cout << i/2+1 << " ";
                } else {
                    cout << N-i/2 << " ";
                }
            }
            cout << N << "\n";
        } else {
            for (int i = 1; i <= N; i++) {
                if (i%2==1) {
                    cout << i/2+1 << " ";
                } else {
                    cout << N-i/2+1 << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}