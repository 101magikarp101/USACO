#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

ll T;
ll N;
ll X, Y;
ll a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> X >> Y;
        for (int i = 0; i < X; i++) {
            cin >> a[i];
        }
        sort(a, a+X);
        ll ans = X-2;
        vt<ll> o, e;
        for (int i = 0; i < X; i++) {
            ll d = i!=X-1?a[i+1]-a[i]:a[0]+N-a[i];
            d--;
            // cout << "i: " << i << " d: " << d << endl;
            if (d>1) {
                if (d%2==0) {
                    e.push_back(d);
                } else {
                    o.push_back(d);
                }
            } else if (d==1) {
                ans++;
            }
        }
        sort(o.begin(), o.end());
        sort(e.begin(), e.end());
        for (int i = 0; i < o.size(); i++) {
            if (Y==0) {
                break;
            }
            if (Y<o[i]/2) {
                ans += Y*2;
                Y = 0;
                break;
            } else if (Y==o[i]/2) {
                ans += o[i];
                Y = 0;
                break;
            } else {
                ans += o[i];
                Y -= o[i]/2;
            }
        }
        for (int i = 0; i < e.size(); i++) {
            if (Y==0) {
                break;
            }
            if (Y<=e[i]/2) {
                ans += Y*2;
                Y = 0;
                break;
            } else {
                ans += e[i];
                Y -= e[i]/2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}