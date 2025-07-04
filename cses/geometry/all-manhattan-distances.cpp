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

void add(vt<int8_t> &v, ll x) {
    rrep(i,sz(v)-1,0) {
        v[i] += x%10;
        if (v[i] >= 10) {
            v[i] -= 10;
            v[i-1]++;
        }
        x /= 10;
    }
}

void add(vt<int8_t> &v, vt<int8_t> &x) {
    rrep(i,sz(v)-1,0) {
        v[i] += x[i];
        if (v[i] >= 10) {
            v[i] -= 10;
            v[i-1]++;
        }
    }
}

void print(vt<int8_t> &v) {
    bool lead = 1;
    bool z = 1;
    rep(i,0,sz(v)) {
        if (lead && v[i] == 0) continue;
        if (v[i] != 0) lead = 0, z = 0;
        cout << (int)v[i];
    }
    if (z) cout << 0;
    cout << endl;
}

int N;

vt<int8_t> solve(vt<ll> &v) {
    ll tot = 0;
    vt<int8_t> ans(21, 0);
    repl(i,0,N) {
        // cout << "v[" << i << "] = " << v[i] << ", tot = " << tot << " res = " << v[i]*i - tot << endl;
        add(ans, v[i]*i - tot);
        // cout << "ans = " << ans << endl;
        tot += v[i];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N;
    vt<ll> x(N), y(N);
    rep(i,0,N) {
        cin >> x[i] >> y[i];
    }
    sort(all(x));
    sort(all(y));
    vt<int8_t> xa = solve(x);
    vt<int8_t> ya = solve(y);
    add(xa, ya);
    print(xa);

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}