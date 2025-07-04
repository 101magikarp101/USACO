#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[33];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        bitset<32> b(N);
        for (int i=0; i<32; i++) {
            a[i] = b[i];
        }
        // cout << "a: ";
        // for (int i = 0; i < 32; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << "\n";
        int r = -1, l = -1;
        for (int i = 0; i < 32; i++) {
            if (a[i]==1) {
                if (l==-1) {
                    l = i;
                }
                r = i;
            } else {
                if (l==-1) {
                    continue;
                }
                if (r==l) {
                    r = -1;
                    l = -1;
                    continue;
                }
                for (int j = l; j <= r; j++) {
                    a[j] = 0;
                }
                a[r+1] = 1;
                a[l] = -1;
                l = i;
                r = i;
            }
        }
        if (l!=-1) {
            for (int j = l; j <= r; j++) {
                a[j] = 0;
            }
            a[r+1] = 1;
            a[l] = -1;
        }
        int last = 0;
        for (int i = 0; i < 32; i++) {
            if (a[i]!=0) {
                last = i;
            }
        }
        cout << last+1 << "\n";
        for (int i = 0; i <= last; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}