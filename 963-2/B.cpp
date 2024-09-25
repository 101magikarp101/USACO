#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N;
ll a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        ll evens = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            if (a[i]%2==0) evens++;
        }
        sort(a, a+N);
        ll o = -1;
        ll odd = -1;
        
        for (int i = N-1; i >= 0; i--) {
            if (a[i]%2==1) {
                o = i;
                odd = a[i];
                break;
            }
        }
        if (o==-1) {
            cout << 0 << endl;
            continue;
        }
        ll ans = 0;
        ll res;
        if (o == N-1) {
            res = evens;
        } else {
            res = evens+1;
        }
        for (int i = 0; i < N; i++) {
            if (i==o) continue;
            if (a[i]%2==0) {
                if (odd < a[i]) {
                    odd+=a[i];
                    a[i]+=odd;
                    if (a[i] > odd) {
                        odd = a[i];
                        o = i;
                    }
                    ans+=2;
                } else {
                    a[i]+=odd;
                    if (a[i] > odd) {
                        odd = a[i];
                        o = i;
                    }
                    ans++;
                }
            }
        }
        ans = min(ans, res);
        cout << ans << endl;
    }
    return 0;
}