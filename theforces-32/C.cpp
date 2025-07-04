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
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(a, a+N);
        ll mi1 = INT_MAX, mi2 = INT_MAX;
        ll ma1 = -1, ma2 = -1;
        for (int i = 0; i < N/2; i++) {
            mi1 = min(mi1, a[i]);
            ma1 = max(ma1, a[i]);
        }
        for (int i = N/2; i < N; i++) {
            mi2 = min(mi2, a[i]);
            ma2 = max(ma2, a[i]);
        }
        ll ans = (ma1-mi1)*(ma2-mi2);
        int res = 0;
        for (int i = 1; i+N/2-1 < N-1; i++) {
            ll temp = (a[i+N/2-1]-a[i])*(a[N-1]-a[0]);
            if (temp < ans) {
                ans = temp;
                res = i;
            }
        }
        if (res == 0) {
            vt<int> v(N, 0);
            for (int i = 0; i < N/2; i++) {
                v[i*2] = a[i];
            }
            for (int i = N/2; i < N; i++) {
                v[(i-N/2)*2+1] = a[i];
            }
            for (int i = 0; i < N; i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        } else {
            vt<int> v(N, 0);
            for (int i = res; i < res+N/2; i++) {
                v[(i-res)*2+1] = a[i];
            }
            int cnt = 0;
            for (int i = 0; i < N; i++) {
                if (i < res || i >= res+N/2) {
                    v[cnt*2] = a[i];
                    cnt++;
                }
            }
            for (int i = 0; i < N; i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}