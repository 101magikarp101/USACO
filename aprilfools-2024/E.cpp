#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N;
int a[200005];
int b[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        b[i] = -1;
    }
    if (N==1) {
        cout << (a[0]==0) << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if (a[i]==0) {
            if (i>0) {
                if (b[i-1]==1) {
                    cout << 0 << endl;
                    return 0;
                } else {
                    b[i-1] = 0;
                }
            }
            if (i<N-1) {
                b[i+1] = 0;
            }
        }
        if (a[i]==2) {
            if (i>0) {
                if (b[i-1]==0) {
                    cout << 0 << endl;
                    return 0;
                } else {
                    b[i-1] = 1;
                }
            } else {
                cout << 0 << endl;
                return 0;
            }
            if (i<N-1) {
                b[i+1] = 1;
            } else {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (b[i]==1) {
            if (i>0) {
                a[i-1]--;
            }
            if (i<N-1) {
                a[i+1]--;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (a[i]<0) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << "a: " << endl;
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    int ans = 0;
    cout << ans << endl;
    return 0;
}