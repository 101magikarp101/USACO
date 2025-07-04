#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
template <class T> using vvt = vt<vt<T>>;
template <class T> using vvvt = vt<vvt<T>>;
template <class T> using vvvvt = vt<vvvt<T>>;
typedef vt<int> vi;
typedef vvt<int> vvi;
typedef vvvt<int> vvvi;
typedef vvvvt<int> vvvvi;
typedef vt<ll> vl;
typedef vvt<ll> vvl;
typedef vvvt<ll> vvvl;
typedef vvvvt<ll> vvvvl;
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)((x).size())
#define mset multiset
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repl(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define rrepl(i,a,b) for(ll i=a;i>=b;i--)
#define each(i,a) for(auto &i:a)
#define yesno(x) cout<<(x?"YES":"NO")<<endl
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
    void operator+=(const pii &a) { x += a.x; y += a.y; }
    void operator-=(const pii &a) { x -= a.x; y -= a.y; }
    void operator*=(const int &a) { x *= a; y *= a; }
    void operator/=(const int &a) { x /= a; y /= a; }
    friend ostream& operator<<(ostream &os, const pii &p) {return os << "(" << p.x << ", " << p.y << ")";}
    friend istream& operator>>(istream &is, pii &p) {return is >> p.x >> p.y;}
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
    void operator+=(const pll &a) { x += a.x; y += a.y; }
    void operator-=(const pll &a) { x -= a.x; y -= a.y; }
    void operator*=(const ll &a) { x *= a; y *= a; }
    void operator/=(const ll &a) { x /= a; y /= a; }
    friend ostream& operator<<(ostream &os, const pll &p) {return os << "(" << p.x << ", " << p.y << ")";}
    friend istream& operator>>(istream &is, pll &p) {return is >> p.x >> p.y;}
};
static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x^(x>>30))*0xbf58476d1ce4e5b9;
    x = (x^(x>>27))*0x94d049bb133111eb;
    return x^(x>>31);
}
struct custom_hash {
    static const uint64_t FIXED_RANDOM;
    size_t operator()(uint64_t x) const {return splitmix64(x + FIXED_RANDOM);}
    template<typename T> size_t operator()(const T& t) const {return splitmix64(uint64_t(std::hash<T>{}(t)) + FIXED_RANDOM);}
};
const uint64_t custom_hash::FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(custom_hash::FIXED_RANDOM);
template<typename K, typename V> using umap = unordered_map<K, V, custom_hash>;
template<typename K> using uset = unordered_set<K, custom_hash>;
template<typename T> using umset = unordered_multiset<T, custom_hash>;
template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

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

int B;

void print(vi &v) {
    rep(i,0,sz(v)) {
        cout << v[i] << " ";
    }
    cout << endl;
}

vi dec(vi &v) {
    vi v1 = v;
    v1[0]--;
    int c = 0;
    rep(i,0,sz(v1)) {
        v1[i] -= c;
        if (v1[i] < 0) {
            v1[i] += 10;
            c = 1;
        } else {
            c = 0;
        }
    }
    while (sz(v1) && v1.back() == 0) {
        v1.pop_back();
    }
    return v1;
}

int di(vi &v) {
    int c = 0;
    rrep(i, sz(v)-1, 0) {
        v[i] += c*10;
        c = v[i]%B;
        v[i] /= B;
    }
    while (sz(v) && v.back() == 0) {
        v.pop_back();
    }
    return c;
}

vi base(vi &v) {
    vi v1;
    while (sz(v)) {
        int c = di(v);
        // cout << "c = " << c << endl;
        // cout << "divided by " << B << ": ";
        // print(v);
        v1.pb(c);
    }
    return v1;
}

vi solve(vi &v) {
    int n = sz(v);
    int m = (B-1)*n;
    vvvi dp(n+1, vvi(m+1, vi(2, 0))); // index, tot, strict
    vvvi pre(n+1, vvi(m+1, vi(2, 0)));
    dp[n][0][1] = 1;
    rep(j,0,m+1) {
        pre[n][j][1] = 1;
    }
    rrep(i,n-1,0) {
        // 1 -> 1
        rep(j,0,m+1) {
            int k = j+(B-1)-v[i];
            if (k >= 0 && k <= m) {
                dp[i][j+(B-1)-v[i]][1] = ad(dp[i][j+(B-1)-v[i]][1], dp[i+1][j][1]);
            }
        }
        // 1 -> 0
        rep(j,0,m+1) {
            int l = B-v[i];
            int r = B-1;
            int l1 = j-r;
            int r1 = j-l;
            int res = 0;
            if (r1 >= 0) {
                res = pre[i+1][r1][1];
            }
            if (l1 > 0) {
                res = sub(res, pre[i+1][l1-1][1]);
            }
            dp[i][j][0] = ad(dp[i][j][0], res);
        }
        // 0 -> 0
        rep(j,0,m+1) {
            int r = B-1;
            int l = 0;
            int l1 = j-r;
            int r1 = j-l;
            int res = 0;
            if (r1 >= 0) {
                res = pre[i+1][r1][0];
            }
            if (l1 > 0) {
                res = sub(res, pre[i+1][l1-1][0]);
            }
            dp[i][j][0] = ad(dp[i][j][0], res);
        }
        pre[i][0][0] = dp[i][0][0];
        pre[i][0][1] = dp[i][0][1];
        rep(j,1,m+1) {
            rep(k,0,2) {
                pre[i][j][k] = ad(pre[i][j-1][k], dp[i][j][k]);
            }
        }
    }
    vi ans(m+1,0);
    rep(j,0,m+1) {
        rep(k,0,2) {
            ans[j] = ad(ans[j], dp[0][j][k]);
        }
    }
    print(ans);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> B;
    string s, t; cin >> s >> t;
    vi l, r;
    int n = sz(s), m = sz(t);
    rep(i,0,n) {
        l.pb(s[n-i-1] - '0');
    }
    rep(i,0,m) {
        r.pb(t[m-i-1] - '0');
    }
    r = base(r);
    cout << "r = ";
    print(r);
    vi ansr = solve(r);
    if (sz(l) != 0 || l[0] != 0) {
        l = dec(l);
        l = base(l);
        cout << "l = ";
        print(l);
        vi ansl = solve(l);
        rep(i,0,sz(ansl)) {
            ansr[i] = sub(ansr[i], ansl[i]);
        }
    }
    print(ansr);
    // int cnt = 0;
    // while (1) {
    //     cur = mul(cur);
    //     vi less = dec(cur);
    //     if (ge(less, l) && ge(r, cur)) {
    //         d = dec(d);
    //         cnt++;
    //     }
    // }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}