#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int C, D;
int a[300005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> C >> D;
        for (int i = 0; i < N*N; i++) {
            cin >> a[i];
        }
        sort(a, a+N*N);
        int x = a[0];
        for (int i = 0; i < N*N; i++) {
            a[i] -= x;
        }
        vt<int> v;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                v.push_back(i*C+j*D);
            }
        }
        sort(v.begin(), v.end());
        bool good = true;
        for (int i = 0; i < N*N; i++) {
            if (a[i] != v[i]) {
                good = false;
                break;
            }
        }
        cout << (good ? "YES" : "NO") << '\n';
    }
    return 0;
}