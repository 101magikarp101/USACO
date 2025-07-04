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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

vvt<int> Manacher(string &s) { // 0 -> {abba, 2}, 1 -> {aba, 1}
    int n = sz(s);             //         ^              ^
    vvt<int> p(2, vt<int>(n, 0));
    rep(z,0,2) {
        int l = 0, r = 0;
        rep(i,0,n) {
            int t = r-i+!z;
            if (i <= r) p[z][i] = min(t, p[z][l+t]);
            int L = i-p[z][i], R = i+p[z][i]-!z;
            while (L > 0 && R < n-1 && s[L-1] == s[R+1]) {
                L--, R++;
                p[z][i]++;
            }
            if (R>r) l = L, r = R;
        }
    }
    return p;
}

vt<int> ls[200005][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    string s; cin >> s;
    vvt<int> m = Manacher(s);
    int N = sz(s);
    vt<int> ans(N,0);
    set<int> s0, s1;
    rep(i,0,N) {
        ls[i+m[1][i]][1].pb(i);
        s1.insert(i);
        if (m[0][i] > 0) {
            ls[i+m[0][i]-1][0].pb(i);
            s0.insert(i);
        }
        int res = 0;
        if (sz(s0) > 0) {
            ckmax(res, (i-*s0.begin())*2+2);
        }
        if (sz(s1) > 0) {
            ckmax(res, (i-*s1.begin())*2+1);
        }
        ans[i] = res;
        each(j,ls[i][0]) {
            s0.erase(j);
        }
        each(j,ls[i][1]) {
            s1.erase(j);
        }
    }
    rep(i,0,N) {
        cout << ans[i] << " ";
    }
    cout << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}