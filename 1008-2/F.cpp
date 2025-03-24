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

int ad(int a, int b) {
    return (a+b)%MOD;
}

int sub(int a, int b) {
    return (a-b+MOD)%MOD;
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

int T, N, Q;
int a[200005];
int fac[200005], ifac[200005];

int nck(int n, int k) {
    return mul(fac[n], mul(ifac[k], ifac[n-k]));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    fac[0] = 1;
    rep(i,1,200005) fac[i] = mul(fac[i-1], i);
    ifac[200004] = inv(fac[200004]);
    rrep(i,200003,0) ifac[i] = mul(ifac[i+1], i+1);
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        string s; cin >> s;
        int zero = 0, one = 0;
        rep(i,0,N) {
            if (s[i] == '0') zero++;
            else one++;
        }
        int cur = 0;
        int sus = 0;
        int off = binpow(2, N);
        rep(i,0,N+1) {
            cur = ad(cur, mul(mul(i-zero, i-zero), nck(N, i)));
            sus = ad(sus, mul(mul(i, 2), nck(N, i)));
        }
        // cout << cur << ' ' << sus << endl;
        int four = inv(4);
        int bi = binpow(2, N-1);
        while (Q--) {
            int x; cin >> x;
            x--;
            if (s[x] == '0') {
                cur = ad(cur, sus);
                cur = ad(cur, mul(off, sub(1, mul(2, zero))));
                zero--;
                one++;
            } else {
                zero++;
                one--;
                cur = sub(cur, sus);
                cur = ad(cur, mul(off, sub(mul(2, zero), 1)));
            }
            // cout << "cur: " << cur << endl;
            s[x] = (1-(s[x]-'0'))+'0';
            // cout << s << " " << zero << " " << one << endl;
            int ans = sub(cur, bi);
            ans = mul(ans, four);
            cout << ans << endl;
        }
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}