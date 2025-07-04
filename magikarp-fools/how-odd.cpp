#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll N;
ll a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    ll cnt = 0;
    ll o = 0;
    for (int i = 0; i < N; i++) {
        string s = to_string(a[i]);
        cnt += s.size();
        for (char c : s) {
            if ((c-'0')%2==1) {
                o++;
            }
        }
    }
    double ans = (double)o/cnt*100;
    cout << fixed << setprecision(3) << ans << endl;
    return 0;
}