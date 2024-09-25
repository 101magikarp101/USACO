#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
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
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        bool hm = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] != i%2) {
                hm = 1;
                break;
            }
        }
        if (hm) {
            for (int i = 0; i < N; i++) {
                cout << i%2 << " ";
            }
            cout << endl;
            continue;
        }
        hm = 0;
        for (int i = 0; i < N; i++) {
            if (i < (N+1)/2) {
                if (a[i] != 0) {
                    hm = 1;
                    break;
                }
            } else {
                if (a[i] != 1) {
                    hm = 1;
                    break;
                }
            }
        }
        if (hm) {
            for (int i = 0; i < N; i++) {
                if (i < (N+1)/2) {
                    cout << 0 << " ";
                } else {
                    cout << 1 << " ";
                }
            }
            cout << endl;
            continue;
        }
        if (N==2) {
            cout << "0 0\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}