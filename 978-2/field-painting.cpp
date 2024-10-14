#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
#define mset multiset
struct pii {
    int x, y;
    bool operator<(const pii &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pii &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pii &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pii &a) const { return x != a.x || y != a.y; }
    pii operator+(const pii &a) const { return {x+a.x, y+a.y}; }
    pii operator-(const pii &a) const { return {x-a.x, y-a.y}; }
    pii operator*(const int &a) const { return {x*a, y*a}; }
    pii operator/(const int &a) const { return {x/a, y/a}; }
};
struct pll {
    ll x, y;
    bool operator<(const pll &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pll &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pll &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pll &a) const { return x != a.x || y != a.y; }
    pll operator+(const pll &a) const { return {x+a.x, y+a.y}; }
    pll operator-(const pll &a) const { return {x-a.x, y-a.y}; }
    pll operator*(const ll &a) const { return {x*a, y*a}; }
    pll operator/(const ll &a) const { return {x/a, y/a}; }
};

struct ppii {
    pii x, y;
};

int T, N, M;
int a[1005];
vt<vt<pii>> adj[21];

int main() {
    auto start = chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int k = 2; k <= 18; k++) {
        adj[k] = vt<vt<pii>>((1<<k), vt<pii>());
        for (int m = 0; m < (1<<k); m++) {
            if (m==0) {
                adj[k][m].pb({(1<<k)-1, (k+1)/2});
                continue;
            }
            vt<ppii> segs;
            int l = -1;
            for (int i = 0; i < k; i++) {
                if ((m&(1<<i))==0) {
                    if (l==-1) {
                        l = i;
                    }
                } else {
                    if (l!=-1) {
                        int d = i-l;
                        if (d%2 == 0) {
                            segs.pb({{l,i-1}, {l-1,i}});
                        } else {
                            segs.pb({{l,i}, {l-1,i-1}});
                        }
                    }
                    l = -1;
                }
            }
            if (l != -1) {
                int d = k-l;
                if (d%2 == 0) {
                    segs.pb({{l,k-1}, {l-1,k}});
                } else {
                    segs.pb({{l,k}, {l-1,k-1}});
                }
            }
            for (int n = 0; n < (1<<sz(segs)); n++) {
                int cur = 0;
                int cnt = 0;
                bool good = 1;
                for (int i = 0; i < sz(segs); i++) {
                    int sus = (n>>i)&1;
                    if (sus == 0) {
                        if (segs[i].x.x < 0) {
                            good = 0;
                            break;
                        }
                        if (segs[i].x.y >= k) {
                            good = 0;
                            break;
                        }
                        cnt += (segs[i].x.y-segs[i].x.x+1)/2;
                        for (int j = segs[i].x.x; j <= segs[i].x.y; j++) {
                            cur |= (1<<j);
                        }
                    } else {
                        if (segs[i].y.x < 0) {
                            good = 0;
                            break;
                        }
                        if (segs[i].y.y >= k) {
                            good = 0;
                            break;
                        }
                        cnt += (segs[i].y.y-segs[i].y.x+1)/2;
                        for (int j = segs[i].y.x; j <= segs[i].y.y; j++) {
                            cur |= (1<<j);
                        }
                    }
                }
                if (!good) continue;
                adj[k][m].pb({cur, cnt});
            }
        }
    }
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            int cur = 0;
            for (int j = 0; j < M; j++) {
                cur |= (s[j]=='#')<<j;
            }
            a[i] = cur;
        }
        a[N] = (1<<M)-1;
        vt<vt<int>> dp(N+1, vt<int>(1<<M, INT_MAX));
        dp[0][a[0]] = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < (1<<M); j++) {
                if (dp[i][j] == INT_MAX) continue;
                for (pii k : adj[M][j]) {
                    int m = a[i+1]|k.x;
                    dp[i+1][m] = min(dp[i+1][m], dp[i][j]+k.y);
                }
            }
        }
        cout << dp[N][(1<<M)-1] << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    cerr << "Time: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms" << endl;
    return 0;
}