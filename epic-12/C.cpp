#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

struct circle {
    ll x, y;
};

int T, N;
circle a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i].x >> a[i].y;
        }
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        ll dist = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        bool good = 1;
        for (int i = 0; i < N; i++) {
            ll d = (a[i].x-x2)*(a[i].x-x2)+(a[i].y-y2)*(a[i].y-y2);
            if (d<=dist) {
                good = 0;
                break;
            }
        }
        cout << (good ? "YES" : "NO") << endl;
    }
    return 0;
}