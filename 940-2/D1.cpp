#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
ll a[100005];
vt<int> h[32];
ll pre[32][100005];
ll p[32][2][100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < 32; i++) {
            h[i].clear();
            for (int j = 0; j < N; j++) {
                pre[i][j] = 0;
                p[i][0][j] = 0;
                p[i][1][j] = 0;
            }
        }
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            ll high = 0;
            for (int j = 31; j >= 0; j--) {
                if (a[i] & (1 << j)) {
                    pre[j][i] = 1;
                    if (j > high) {
                        high = j;
                    }
                }
            }
            h[high].push_back(i);
        }
        for (int i = 0; i < 32; i++) {
            p[i][pre[i][0]%2][0]++;
            for (int j = 1; j < N; j++) {
                pre[i][j]+=pre[i][j-1];
                p[i][pre[i][j]%2][j]++;
            }
        }
        for (int i = 0; i < 32; i++) {
            for (int j = 1; j < N; j++) {
                p[i][0][j] += p[i][0][j-1];
                p[i][1][j] += p[i][1][j-1];
            }
        }
        ll ans = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < h[i].size(); j++) {
                ll res = 0;
                if (h[i][j]>0) {
                    res+=(p[i][0][h[i][j]-1]+1)*(p[i][0][N-1]-p[i][0][h[i][j]-1]);
                    res+=p[i][1][h[i][j]-1]*(p[i][1][N-1]-p[i][1][h[i][j]-1]);
                } else {
                    res+=p[i][0][N-1];
                }
                ans+=res;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}