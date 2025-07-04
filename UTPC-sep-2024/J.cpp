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

int N, Q, sq;
int a[10005];
vt<vt<ll>> v(101, vt<ll>(13,0));
vt<vt<ll>> dp(101, vt<ll>(13,0));
vt<vt<ll>> pre(101, vt<ll>(13,0));

ll ad(ll a, ll b) {
    return (a+b)%MOD2;
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b%2) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD2-2);
}

ll di(ll a, ll b) {
    return mul(a, inv(b));
}

void init() {
    for (int i = 0; i < N; i+=sq) {
        for (int j = 0; j <= sq; j++) {
            for (int k = 0; k < 13; k++) {
                dp[j][k] = 0;
                pre[j][k] = 0;
            }
        }
        dp[0][a[i]] = 1;
        pre[0][a[i]] = 1;
        for (int j = i+1; j < min(N, i+sq); j++) {
            int jj = j-i;
            dp[jj][a[j]] = ad(dp[jj][a[j]], 1);
            for (int k = 0; k < 13; k++) {
                dp[jj][(k*a[j])%13] = ad(dp[jj][(k*a[j])%13], pre[jj-1][k]);
            }
            for (int k = 0; k < 13; k++) {
                pre[jj][k] = ad(pre[jj-1][k], dp[jj][k]);
            }
        }
        for (int k = 0; k < 13; k++) {
            v[i/sq][k] = pre[min(sq,N-i)-1][k];
        }
    }
}

void upd(ll idx, ll val) {
    a[idx] = val;
    for (int i = 0; i <= sq; i++) {
        for (int j = 0; j < 13; j++) {
            dp[i][j] = 0;
            pre[i][j] = 0;
        }
    }
    int left = (idx/sq)*sq;
    dp[0][a[left]] = 1;
    pre[0][a[left]] = 1;
    for (int i = left+1; i < min(N, left+sq); i++) {
        int ii = i-left;
        dp[ii][a[i]] = 1;
        for (int j = 0; j < 13; j++) {
            dp[ii][(j*a[i])%13] = ad(dp[ii][(j*a[i])%13], pre[ii-1][j]);
        }
        for (int j = 0; j < 13; j++) {
            pre[ii][j] = ad(pre[ii-1][j], dp[ii][j]);
        }
    }
    for (int i = 0; i < 13; i++) {
        v[left/sq][i] = pre[min(sq,N-left)-1][i];
    }
}

vt<ll> solvel(int idx, int lb) {
    for (int i = 0; i <= sq; i++) {
        for (int j = 0; j < 13; j++) {
            dp[i][j] = 0;
            pre[i][j] = 0;
        }
    }
    dp[0][a[idx]] = 1;
    pre[0][a[idx]] = 1;
    int up = min(N, lb+sq);
    for (int i = idx+1; i < up; i++) {
        int ii = i-idx;
        dp[ii][a[i]] = 1;
        for (int j = 0; j < 13; j++) {
            dp[ii][(j*a[i])%13] = ad(dp[ii][(j*a[i])%13], pre[ii-1][j]);
        }
        for (int j = 0; j < 13; j++) {
            pre[ii][j] = ad(pre[ii-1][j], dp[ii][j]);
        }
    }
    vt<ll> res(13,0);
    for (int i = 0; i < 13; i++) {
        res[i] = pre[up-idx-1][i];
    }
    return res;
}

vt<ll> solver(int idx, int rb) {
    for (int i = 0; i <= sq; i++) {
        for (int j = 0; j < 13; j++) {
            dp[i][j] = 0;
            pre[i][j] = 0;
        }
    }
    dp[0][a[rb]] = 1;
    pre[0][a[rb]] = 1;
    for (int i = rb+1; i <= idx; i++) {
        int ii = i-rb;
        dp[ii][a[i]] = 1;
        for (int j = 0; j < 13; j++) {
            dp[ii][(j*a[i])%13] = ad(dp[ii][(j*a[i])%13], pre[ii-1][j]);
        }
        for (int j = 0; j < 13; j++) {
            pre[ii][j] = ad(pre[ii-1][j], dp[ii][j]);
        }
    }
    vt<ll> res(13,0);
    for (int i = 0; i < 13; i++) {
        res[i] = pre[idx-rb][i];
    }
    return res;
}

ll solve(int l, int r) {
    int lb = l/sq*sq;
    int rb = r/sq*sq;
    if (lb == rb) {
        for (int i = 0; i <= sq; i++) {
            for (int j = 0; j < 13; j++) {
                dp[i][j] = 0;
                pre[i][j] = 0;
            }
        }
        dp[0][a[l]] = 1;
        pre[0][a[l]] = 1;
        for (int i = l+1; i <= r; i++) {
            int ii = i-l;
            dp[ii][a[i]] = 1;
            for (int j = 0; j < 13; j++) {
                dp[ii][(j*a[i])%13] = ad(dp[ii][(j*a[i])%13], pre[ii-1][j]);
            }
            for (int j = 0; j < 13; j++) {
                pre[ii][j] = ad(pre[ii-1][j], dp[ii][j]);
            }
        }
        return pre[r-l][5];
    } else {
        vt<ll> lans = solvel(l, lb);
        vt<ll> rans = solver(r, rb);
        for (int i = 0; i <= sq; i++) {
            for (int j = 0; j < 13; j++) {
                dp[i][j] = 0;
                pre[i][j] = 0;
            }
        }
        for (int i = 0; i < 13; i++) {
            dp[lb/sq][i] = lans[i];
            pre[lb/sq][i] = lans[i];
        }
        for (int i = lb+sq; i < rb; i+=sq) {
            for (int j = 0; j < 13; j++) {
                dp[i/sq][j] = v[i/sq][j];
            }
            for (int j = 0; j < 13; j++) {
                for (int k = 0; k < 13; k++) {
                    dp[i/sq][(j*k)%13] = ad(dp[i/sq][(j*k)%13], mul(pre[i/sq-1][j], v[i/sq][k]));
                }
            }
            for (int j = 0; j < 13; j++) {
                pre[i/sq][j] = ad(pre[i/sq-1][j], dp[i/sq][j]);
            }
        }
        for (int i = 0; i < 13; i++) {
            dp[rb/sq][i] = rans[i];
        }
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 13; j++) {
                dp[rb/sq][(i*j)%13] = ad(dp[rb/sq][(i*j)%13], mul(rans[i], pre[rb/sq-1][j]));
            }
        }
        for (int i = 0; i < 13; i++) {
            pre[rb/sq][i] = ad(pre[rb/sq-1][i], dp[rb/sq][i]);
        }
        return pre[rb/sq][5];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    sq = sqrt(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i] %= 13;
    }
    init();
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y;
            y %= 13;
            upd(x-1, y);
        } else {
            int l, r; cin >> l >> r;
            l--; r--;
            ll ans = solve(l, r);
            cout << ans << endl;
        }
    }
    return 0;
}