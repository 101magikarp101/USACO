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

template <class T> class BIT {
    // MUST be 1-indexed
public:
    vector<T> bit;
    int size;
    BIT(int n) {size = n; bit.resize(n + 1);}
    void upd(int i, T x) {
        for (; i <= size; i += i & -i) bit[i] += x;
    }
    // returns sum of [1, i]
    T sum(int i) {
        T s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
    // returns sum of [l, r]
    T sum(int l, int r) {
        return sum(r) - (l>1 ? sum(l-1) : 0);
    }
};

int N;
vi a;
ll p[200005], s[200005];
int idx = -1;

void comp() {
    set<int> s;
    rep(i,0,N) {
        s.insert(a[i]);
    }
    map<int,int> m;
    each(i,s) {
        m[i] = sz(m);
    }
    rep(i,0,N) {
        a[i] = m[a[i]];
    }
}

void pre() {
    comp();
    rep(i,0,N) {
        if (a[i] == N-1) {
            a.erase(a.begin() + i);
            idx = i;
            break;
        }
    }
    N--;
    BIT<ll> bit(N);
    rep(i,0,N) {
        if (i) p[i] = p[i-1];
        p[i] += bit.sum(a[i]+1, N);
        bit.upd(a[i]+1, 1);
    }
    bit = BIT<ll>(N);
    rrep(i,N-1,0) {
        if (i < N-1) s[i] = s[i+1];
        s[i] += bit.sum(a[i]+1, N);
        bit.upd(a[i]+1, 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N;
    a.resize(N);
    rep(i,0,N) cin >> a[i];
    pre();
    // cout << "a: ";
    // rep(i,0,N) cout << a[i] << " ";
    // cout << endl;
    // cout << "p: ";
    // rep(i,0,N) cout << p[i] << " ";
    // cout << endl;
    // cout << "s: ";
    // rep(i,0,N) cout << s[i] << " ";
    // cout << endl;
    // cout << "N: " << N << endl;
    ll ans = min(p[N-1]+N-idx, s[0]+idx);
    // cout << "idx: " << idx << endl;
    // cout << "ans: " << ans << endl;
    rep(i,0,N-1) {
        ll res = p[i] + s[i+1] + max(0, abs(idx - i - 1));
        // cout << "i: " << i << ", res: " << res << endl;
        ckmin(ans, res);
    }
    cout << ans << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}