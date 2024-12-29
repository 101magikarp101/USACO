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
#define rrep(i,a,b) for(int i=a;i>=b;i--)
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

int T, N, Q;
int a[200005], b[200005];
umap<int,int> ma, mb;
umap<int,int> ra, rb;

int ad(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int sub(int a, int b) {
    a-=b;
    if (a<0) a+=MOD;
    return a;
}

int mul(int a, int b) {
    return (int)((a*1LL*b)%MOD);
}

int binpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return binpow(a, MOD-2);
}

int di(int a, int b) {
    return mul(a, inv(b));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        ma.clear();
        mb.clear();
        ra.clear();
        rb.clear();
        vt<pii> va, vb;
        rep(i,0,N) {
            cin >> a[i];
            va.pb({a[i], i+1});
        }
        rep(i,0,N) {
            cin >> b[i];
            vb.pb({b[i], i+1});
        }
        sort(all(va));
        sort(all(vb));
        sort(a, a+N);
        sort(b, b+N);
        rep(i,0,N) {
            ma[va[i].y] = i;
            mb[vb[i].y] = i;
            ra[i] = va[i].y;
            rb[i] = vb[i].y;
        }
        int ans = 1;
        rep(i,0,N) {
            ans = mul(ans, min(a[i], b[i]));
        }
        cout << ans << ' ';
        while (Q--) {
            int c, x; cin >> c >> x;
            if (c == 1) {
                int i = ma[x];
                auto it = upper_bound(a, a+N, a[i]);
                int j = it-a-1;
                ans = di(ans, min(a[j], b[j]));
                a[j]++;
                ans = mul(ans, min(a[j], b[j]));
                swap(ra[i], ra[j]);
                swap(ma[x], ma[ra[i]]);
            } else {
                int i = mb[x];
                auto it = upper_bound(b, b+N, b[i]);
                int j = it-b-1;
                ans = di(ans, min(a[j], b[j]));
                b[j]++;
                ans = mul(ans, min(a[j], b[j]));
                swap(rb[i], rb[j]);
                swap(mb[x], mb[rb[i]]);
            }
            cout << ans << ' ';
        }
        cout << endl;
    }
    return 0;
}