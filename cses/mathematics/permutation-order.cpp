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

int T, N;
ll fac[21];

vt<int> v;

void pre(int n) {
    fac[0] = 1;
    rep(i,1,n+1) fac[i] = fac[i-1]*i;
}

void solve1(int n, ll k, vt<int> &a) {
    if (n == 0) return;
    int i = k/fac[n-1];
    v.pb(a[i]);
    k %= fac[n-1];
    a.erase(a.begin() + i);
    solve1(n-1, k, a);
}

ll solve2(int n, vt<int> &a) {
    vt<int> b(n);
    rep(i,0,n) b[i] = i+1;
    ll ans = 1;
    rep(i,0,n) {
        int j = find(all(b), a[i]) - b.begin();
        ans += j * fac[n-i-1];
        b.erase(b.begin() + j);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    pre(20);
    cin >> T;
    while (T--) {
        int x; cin >> x;
        if (x == 1) {
            int n; ll k; cin >> n >> k;
            k--;
            v.clear();
            vt<int> a(n);
            rep(i,0,n) a[i] = i+1;
            solve1(n, k, a);
            rep(i,0,n) {
                cout << v[i] << " ";
            }
            cout << endl;
        } else {
            int n; cin >> n;
            vt<int> a(n);
            rep(i,0,n) cin >> a[i];
            ll ans = solve2(n, a);
            cout << ans << endl;
        }
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}