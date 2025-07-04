#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N, Q;
int a[200005];
map<ll, ll> m;
int ans1[200005], ans2[200005];
ll ans3[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        m[a[i]] = i;
    }
    int mex = 0;
    for (auto i : m) {
        if (i.first!=mex) {
            break;
        }
        mex++;
    }
    ll l = a[0], r = a[0];
    for (int i = 0; i < mex; i++) {
        l = min(l, m[i]);
        r = max(r, m[i]);
        if (m.find(i+1)==m.end()) {
            ans1[i+1] = r-l+1;
            ans2[i+1] = N;
            ans3[i+1] = (l+1)*(N-r);
        } else {
            int x = m[i+1];
            if (l>=x && x<=r) {
                ans1[i+1] = -1;
                ans2[i+1] = -1;
                ans3[i+1] = -1;
            } else {
                ans1[i+1] = r-l+1;
                if (x < l) {
                    ans2[i+1] = N-x-1;
                    ans3[i+1] = (l-x)*(N-r);
                } else if (x > r) {
                    ans2[i+1] = x;
                    ans3[i+1] = (l+1)*(x-r);
                }
            }
        }
    }
    while (Q--) {
        int x; cin >> x;
        if (x==0) {
            int res1 = (N==1&&a[0]==0?-1:1);
            if (res1==-1) {
                cout << -1 << '\n';
            } else {
                int res2 = max(a[0], N-a[0]-1);
                ll res3 = (a[0]*(a[0]-1)/2)+((N-a[0]-1)*(N-a[0]-2)/2);
                cout << res1 << ' ' << res2 << ' ' << res3 << '\n';
            }
        } else if (x<=mex) {
            cout << ans1[x] << ' ' << ans2[x] << ' ' << ans3[x] << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}