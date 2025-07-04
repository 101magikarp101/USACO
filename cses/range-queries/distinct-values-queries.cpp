#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
template <class T> using vvt = vt<vt<T>>;
template <class T> using vvvt = vt<vvt<T>>;
template <class T> using vvvvt = vt<vvvt<T>>;
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
#define repl(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define rrepl(i,a,b) for(ll i=a;i>=b;i--)
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

struct query {
    int l, r, i;
    bool operator<(const query &a) const { return r < a.r; }
};

int N, Q;
int M;
int a[200005];
int ans[200005];
vt<query> qs[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> Q;
    M = sqrt(N)+1;
    set<int> s;
    rep(i,0,N) {
        cin >> a[i];
        s.insert(a[i]);
    }
    map<int,int> m;
    each(x,s) {
        m[x] = sz(m);
    }
    rep(i,0,N) {
        a[i] = m[a[i]];
    }
    int n = sz(s);
    rep(i,0,Q) {
        int l, r; cin >> l >> r;
        l--; r--;
        qs[l/M].pb({l, r, i});
    }
    rep(i,0,M) {
        sort(all(qs[i]));
        vt<int> cnt(n,0);
        int cur = 0;
        int curl = i*M, curr = i*M;
        cnt[a[curl]]++;
        cur = 1;
        each(q,qs[i]) {
            int l = q.l, r = q.r, idx = q.i;
            while (curr < r) {
                curr++;
                cnt[a[curr]]++;
                if (cnt[a[curr]] == 1) cur++;
            }
            while (curl < l) {
                cnt[a[curl]]--;
                if (cnt[a[curl]] == 0) cur--;
                curl++;
            }
            while (curl > l) {
                curl--;
                cnt[a[curl]]++;
                if (cnt[a[curl]] == 1) cur++;
            }
            ans[idx] = cur;
        }
    }
    rep(i,0,Q) {
        cout << ans[i] << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}