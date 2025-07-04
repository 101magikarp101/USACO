#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

int T;
ll N;
int X, Y;
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
        int ans = X-2;
        vt<int> o, e;
        for (int i = 0; i < X; i++) {
            ll d = min(abs(a[i]-a[(i+1)%X]), N-abs(a[i]-a[(i+1)%X]));
            if (d!=0) {
                if (d%2==0) {
                    e.push_back(d);
                } else {
                    o.push_back(d);
                }
            }
        }
        sort(o.begin(), o.end(), greater<int>());
        sort(e.begin(), e.end(), greater<int>());
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