#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, S;
ll a[300005];

int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> N >> S;
        if (S < N || S > N*(N+1)/2) {
            cout << "-1" << endl;
            continue;
        }
        ll hm = N+1;
        for (int i = N; i >= 1; i--) {
            if (S >= i) {
                S -= i;
                a[i] = i;
                hm = i;
            } else {
                a[i] = S;
                S = 0;
                hm = i;
                break;
            }
        }
        // cout << "a: ";
        // for (int i = 1; i <= N; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        // cout << "hm: " << hm << endl;
        vt<ll> ans;
        for (int i = hm; i >= 0; i--) {
            if (i!=a[hm]) ans.push_back(i);
        }
        if (hm<N) ans.push_back(a[hm]);
        for (int i = hm+1; i <= N-1; i++) {
            ans.push_back(i);
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}