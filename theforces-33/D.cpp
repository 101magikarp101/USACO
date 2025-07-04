#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        if (M == N*(N+1)/2 || M == -N*(N+1)/2) {
            cout << "NO" << endl;
            continue;
        }
        ll hm = N%4;
        if (hm == 0 || hm == 3) {
            if (abs(M)%2 == 1) {
                cout << "NO" << endl;
                continue;
            }
        } else {
            if (abs(M)%2 == 0) {
                cout << "NO" << endl;
                continue;
            }
        }
        vt<ll> p, n;
        for (ll i = N; i >= 1; i--) {
            if (M >= 0) {
                p.push_back(i);
                M -= i;
            } else {
                n.push_back(i);
                M += i;
            }
        }
        cout << "YES" << endl;
        while (p.size() > 1) {
            ll x = p.back();
            ll y = n.back();
            cout << y << " " << x << endl;
            p.pop_back();
            n.pop_back();
            n.push_back(y-x);
        }
        while (!n.empty()) {
            ll x = p.back();
            ll y = n.back();
            cout << x << " " << y << endl;
            p.pop_back();
            n.pop_back();
            p.push_back(x-y);
        }
    }
    return 0;
}