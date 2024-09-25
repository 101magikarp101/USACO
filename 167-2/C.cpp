#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
pii a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i].x;
        }
        for (int i = 0; i < N; i++) {
            cin >> a[i].y;
        }
        int x = 0, y = 0;
        int neg = 0, pos = 0;
        for (int i = 0; i < N; i++) {
            int xx = a[i].x;
            int yy = a[i].y;
            if (xx==yy) {
                if (xx==-1) {
                    neg++;
                } else if (xx==1) {
                    pos++;
                }
            } else if (xx==1) {
                x+=xx;
            } else if (yy==1) {
                y+=yy;
            }
        }
        while (neg > 0) {
            if (x>y) {
                x--;
            } else {
                y--;
            }
            neg--;
        }
        while (pos > 0) {
            if (x>y) {
                y++;
            } else {
                x++;
            }
            pos--;
        }
        cout << min(x, y) << endl;
    }
    return 0;
}