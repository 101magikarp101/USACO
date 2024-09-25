#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M, A, B;
int a[200005];
int dist = 0, t = 0;

bool check(int x) {
    bool good = 1;
    for (int i = x; i >= 0; i--) {
        // cout << "i: " << i << " x: " << x << "\n";
        // cout << "a[i]+(x-i): " << a[i]+(x-i) << " t: " << t << "\n";
        if (a[i]+(x-i+1) > t) {
            good = 0;
            break;
        }
    }
    return good;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M >> A >> B;
        for (int i = 0; i < M; i++) {
            cin >> a[i];
        }
        dist = 0, t = 0;
        if (A<B) {
            dist = B-A;
            t = dist+A-1;
        } else {
            dist = A-B;
            t = dist+N-A;
        }
        sort(a, a+M);
        // cout << "dist: " << dist << " t: " << t << "\n";
        if (dist <= 1) {
            cout << 0 << endl;
            continue;
        }
        if (!check(0)) {
            cout << 0 << endl;
            continue;
        }
        int l = 0, r = min(M-1, dist-2);
        while (l<r) {
            int m = (l+r+1)/2;
            if (check(m)) {
                l = m;
            } else {
                r = m-1;
            }
        }
        cout << l+1 << "\n";
    }
    return 0;
}