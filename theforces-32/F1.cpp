#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

struct seg {
    ll r, v;
    bool operator<(const seg& s) const {
        return r < s.r;
    }
};

ll T, N, M, Q;
ll dp[2005][2005];
ll pre[2005][2005];
ll calc[2005][2005];
vt<seg> segs[2005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M >> Q;
        for (int i = 1; i <= N; i++) {
            segs[i].clear();
        }
        for (int i = 0; i < M; i++) {
            ll l, r, v;
            cin >> l >> r >> v;
            if (l > r) {
                swap(l, r);
            }
            segs[l].push_back({r, v});
        }
        for (int i = 1; i <= N; i++) {
            multiset<seg> s;
            for (int j = 0; j < segs[i].size(); j++) {
                s.insert(segs[i][j]);
            }
            ll tot = 0;
            for (int j = i+1; j <= N; j++) {
                while (s.size() && s.begin()->r <= j) {
                    tot+=s.begin()->v;
                    s.erase(s.begin());
                }
                calc[i][j] = tot;
                for (int k = 0; k < segs[j].size(); k++) {
                    s.insert(segs[j][k]);
                }
            }
        }
        cout << "calc: " << endl;
        for (int i = 1; i <= N; i++) {
            for (int j = i+1; j <= N; j++) {
                cout << calc[i][j] << " ";
            }
            cout << endl;
        }
        vt<ll> ans(N, 0);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N-1; j++) {
                for (int k = i; k >= 1; k--) {
                    if (j-(i-k) < 0) {
                        break;
                    }
                    dp[i][j] = max(dp[i][j], dp[k-1][j-(i-k)]+calc[k][i]);
                }
            }
        }
        cout << "dp: " << endl;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N-1; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < Q; i++) {
            ll x;
            cin >> x;
            if (x >= N) {
                x = N-1;
            }
            cout << dp[N][x] << endl;
        }
    }
    return 0;
}