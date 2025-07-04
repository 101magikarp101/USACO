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

int P;

int add(int x, int y) {
    x += y;
    if (x >= P) x -= P;
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0) x += P;
    return x;
}

int mul(int x, int y) {
    return (int)((x*1ll*y) % P);
}

int binpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = mul(res, x);
        x = mul(x, x);
        y >>= 1;
    }
    return res;
}

int inv(int x) {
    return binpow(x, P - 2);
}

int N;
int fac[5005], ifac[5005];

void pre(int n) {
    fac[0] = 1;
    rep(i, 1, n + 1) fac[i] = mul(fac[i - 1], i);
    ifac[n] = inv(fac[n]);
    rrep(i, n - 1, 0) ifac[i] = mul(ifac[i + 1], i + 1);
}

int nck(int n, int k) {
    if (k < 0 || k > n) return 1;
    return mul(fac[n], mul(ifac[k], ifac[n-k]));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> P;
    pre(5000);
    int ans = 0;
    rep(l,-1,(N-1)/2) {
        int x = N-l-2;
        int y = l+1+(N%2==0);
        rep(i,0,max(1,l+1)) {
            int res = mul(nck(l, i), mul(fac[x-1+i], y));
            ans = add(ans, res);
        }
    }
    ans = mul(ans, N);
    cout << ans << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}