#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N;
int a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    if (is_sorted(a, a+N)) {
        cout << "yes" << "\n" << 1 << " " << 1 << "\n";
        return 0;
    }
    int l = -1, r = -1;
    for (int i = 1; i < N; i++) {
        if (a[i] < a[i-1]) {
            if (l == -1) {
                l = i-1;
            }
            r = i;
        } else {
            if (l != -1) {
                break;
            }
        }
    }
    reverse(a+l, a+r+1);
    if (is_sorted(a, a+N)) {
        cout << "yes" << "\n" << l+1 << " " << r+1 << "\n";
        return 0;
    }
    cout << "no" << "\n";
    return 0;
}