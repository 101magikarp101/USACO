#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a,a+N, [&](int x, int y) {
        int a = 0;
        int xx = x;
        while (xx) {
            a+=xx%10;
            xx/=10;
        }
        int b = 0;
        int yy = y;
        while (yy) {
            b+=yy%10;
            yy/=10;
        }
        a %= 13;
        b %= 13;
        if (a == b) return x > y;
        return a > b;
    });
    for (int i = 0; i < M; i++) {
        cout << a[i] << endl;
    }
    return 0;
}