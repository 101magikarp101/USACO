#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)((x).size())
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define each(i,a) for(auto &i:a)
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

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

ll N, M, S, T;
ll a[3005][3005];
ll d[3005][3005];
ll l[3005][3005];

int find(vt<pll> &v, ll x) {
    if (sz(v)==0) return 0;
    int l = 0, r = sz(v)-1;
    while (l<r) {
        int m = (l+r+1)/2;
        if (v[m].y <= x) {
            l = m;
        } else {
            r = m-1;
        }
    }
    // cout << "l " << l << endl;
    if (v[l].y > x) return -1;
    else return l;
    // return l;
}

ll solve(ll x, ll y, int i) {
    ll ans = 0;
    vt<pll> v; //{idx, val}
    mset<ll> cur;
    rep(j,0,M) {
        cur.insert(d[i][j]);
        if (j >= y) cur.erase(cur.find(d[i][j-y]));
        if (j >= y-1) {
            while (!v.empty() && v.back().y > d[i][j-y+1]) {
                v.back().y = d[i][j-y+1];
                if (v.back().y < x) {
                    v.pop_back();
                    continue;
                }
                if (sz(v) >= 2) {
                    if (v[sz(v)-2].y >= d[i][j-y+1]) {
                        v.pop_back();
                    }
                }
            }
            if ((v.empty() || d[i][j-y+1] > v.back().y) && d[i][j-y+1] >= x) v.pb({j-y+1, d[i][j-y+1]});
        }
        ll hm = *cur.begin();
        while (!v.empty() && v.back().y > hm) {
            v.back().y = hm;
            if (v.back().y < x) {
                v.pop_back();
                continue;
            }
            if (sz(v) >= 2) {
                if (v[sz(v)-2].y >= hm) {
                    v.pop_back();
                }
            }
        }
        if (d[i][j] <= d[i][j+1]) continue;
        auto it = (i==0)?v.end():upper_bound(all(v), pll{j-l[i-1][j],(ll)1e9});
        int idx = it-v.begin();
        int idx2 = find(v, d[i][j+1]);
        // cout << "search " << j-l[i-1][j] << endl;
        // cout << "search2 " << d[i][j+1] << endl;
        // cout << "j " << j << " " << idx << " " << idx2 << endl;
        // cout << "v ";
        // each(i,v) cout << "(" << i.x << "," << i.y << ") ";
        // cout << endl;
        ll res = max(0, idx-idx2-1);
        ans += res;
    }
    // cout << "solve " << x << " " << y << " " << i << " " << ans << endl;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> S >> T;
    rep(i,0,N) {
        string s; cin >> s;
        rep(j,0,M) {
            a[i][j] = s[j]=='0';
        }
    }
    rep(j,0,M) {
        ll cur = N;
        for (int i = N-1; i >= 0; i--) {
            if (a[i][j]) {
                cur = i;
            }
            d[i][j] = cur-i;
        }
    }
    rep(i,0,N) {
        ll cur = -1;
        rep(j,0,M) {
            if (a[i][j]) {
                cur = j;
            }
            l[i][j] = j-cur;
        }
    }
    ll ans = 0;
    ll ma = max(S,T);
    rep(i,0,N) {
        ans += solve(S,T,i);
        ans += solve(T,S,i);
        ans -= solve(ma,ma,i);
    }
    cout << ans << endl;
    return 0;
}