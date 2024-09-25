#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, Q;
int a[200005];
int l[200005][16], r[200005][16];

int conv(char c) {
    if (c=='B') return 0;
    if (c=='G') return 1;
    if (c=='R') return 2;
    return 3;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            a[i] = 0;
            a[i] |= 1<<conv(s[0]);
            a[i] |= 1<<conv(s[1]);
        }
        vt<int> left(16, -1);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 16; j++) {
                l[i][j] = left[j];
            }
            left[a[i]] = i;
        }
        vt<int> right(16, -1);
        for (int i = N-1; i >= 0; i--) {
            for (int j = 0; j < 16; j++) {
                r[i][j] = right[j];
            }
            right[a[i]] = i;
        }
        while (Q--) {
            int n,m; cin >> n >> m;
            n--; m--;
            int x = a[n], y = a[m];
            int ans = INT_MAX;
            for (int i = 0; i < 4; i++) {
                if (x&(1<<i) && y&(1<<i)) {
                    ans = abs(n-m);
                    break;
                }
            }
            if (ans!=INT_MAX) {
                cout << ans << endl;
                continue;
            }
            for (int mask = 3; mask < 16; mask++) {
                if (__builtin_popcount(mask)==2) {
                    int cnt0 = 0, cnt1 = 0;
                    for (int i = 0; i < 4; i++) {
                        if (mask&(1<<i)) {
                            if (x&(1<<i)) {
                                cnt0++;
                            }
                            if (y&(1<<i)) {
                                cnt1++;
                            }
                        }
                    }
                    if (cnt0==1 && cnt1==1) {
                        if (l[n][mask]!=-1) {
                            ans = min(ans, abs(m-l[n][mask])+abs(n-l[n][mask]));
                        }
                        if (r[n][mask]!=-1) {
                            ans = min(ans, abs(m-r[n][mask])+abs(n-r[n][mask]));
                        }
                    }
                }
            }
            if (ans==INT_MAX) {
                cout << -1 << endl;
            } else {
                cout << ans << endl;
            }
        }
    }
    return 0;
}