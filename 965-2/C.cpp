#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, K;
pll a[200005];

bool check1(ll x, int n) {
    int cnt = 0;
    ll tot = 0;
    for (int i = N-1; i >= 0; i--) {
        if (i==n) continue;
        if (a[i].y==0) {
            if (a[i].x >= x) cnt++;
        } else {
            if (a[i].x >= x) cnt++;
            else {
                tot += max(0ll, x-a[i].x);
                cnt++;
            }
        }
        if (cnt >= (N+1)/2) break;
    }
    return cnt >= (N+1)/2 && tot <= K;
}

bool check2(ll x, int n) {
    int cnt = 0;
    ll tot = 0;
    for (int i = N-1; i >= 0; i--) {
        if (i==n) continue;
        if (a[i].y==0) {
            if (a[i].x >= x) cnt++;
        } else {
            if (a[i].x >= x) cnt++;
            else {
                tot += max(0ll, x-a[i].x);
                cnt++;
            }
        }
        if (cnt >= (N+1)/2) break;
    }
    return cnt >= (N+1)/2 && tot <= K;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> a[i].x;
        }
        for (int i = 0; i < N; i++) {
            cin >> a[i].y;
        }
        bool allz = 1;
        for (int i = 0; i < N; i++) {
            if (a[i].y != 0) {
                allz = 0;
                break;
            }
        }
        sort(a, a+N, [](pll a, pll b) {
            return a.x < b.x;
        });
        ll ans = 0;
        for (int i = N/2-1; i >= 0; i--) {
            if (a[i].y == 0) {
                ll l = 0, r = 1e10;
                while (l<r) {
                    ll m = (l+r+1)/2;
                    if (check1(m, i)) {
                        l = m;
                    } else {
                        r = m-1;
                    }
                }
                ans = max(ans, a[i].x+l);
                break;
            }
        }
        // cout << "ans1: " << ans << endl;
        for (int i = N-1; i >= N/2; i--) {
            if (a[i].y == 0) {
                ll l = 0, r = 1e10;
                while (l<r) {
                    ll m = (l+r+1)/2;
                    if (check2(m, i)) {
                        l = m;
                    } else {
                        r = m-1;
                    }
                }
                ans = max(ans, a[i].x+l);
                break;
            }
        }
        // cout << "ans2: " << ans << endl;
        for (int i = 0; i < N; i++) {
            if (a[i].y == 0) continue;
            if (i < N/2) {
                ans = max(ans, a[i].x+K+a[N/2].x);
            } else {
                ans = max(ans, a[i].x+K+a[N/2-1].x);
            }
        }
        cout << ans << endl;
    }
    return 0;
}