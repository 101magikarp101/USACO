#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N, M;
pll a[1000005];
ll res[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a[i].x;
    }
    for (int i = 0; i < N; i++) {
        cin >> a[i].y;
        a[i].y = a[i].x-a[i].y;
    }
    sort(a, a+N, [](pll a, pll b) {
        if (a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    });
    vt<pll> b;
    for (int i = 0; i < N; i++) {
        if (b.empty() || (b.back().y < a[i].y && b.back().x > a[i].x)) {
            b.push_back(a[i]);
        }
    }
    // cout << "b: ";
    // for (int i = 0; i < b.size(); i++) {
    //     cout << b[i].x << " " << b[i].y << endl;
    // }
    // cout << endl;
    N = b.size();
    for (int i = 0; i <= 1000001; i++) {
        res[i] = 0;
    }
    int cur = N-1;
    for (int i = 0; i <= 1000000; i++) {
        if (cur>0 && b[cur-1].x <= i) {
            cur--;
        }
        if (b[cur].x <= i) {
            res[i] = res[i-b[cur].y]+2;
        }
    }
    // for (int i = 0; i <= 20; i++) {
    //     cout << "res[" << i << "]: " << res[i] << endl;
    // }
    ll ans = 0;
    while (M--) {
        ll x; cin >> x;
        if (x <= 1000000) {
            ans += res[x];
        } else {
            ll r = ((x-b[0].x)/b[0].y+1)*2;
            x -= ((x-b[0].x)/b[0].y+1)*b[0].y;
            r += res[x];
            ans += r;
        }
    }
    cout << ans << endl;
    return 0;
}