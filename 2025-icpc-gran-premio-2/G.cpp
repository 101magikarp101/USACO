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

__int128 cross(const pll &a, const pll &b) {
    return (__int128)a.x * b.y - (__int128)a.y * b.x;
}

struct ang {
    ll x, y, t;
    // sort by angle
    bool operator<(const ang &a) const {
        int ha = half(), hb = a.half();
        if (ha != hb) return ha < hb;
        else return cross({x, y}, {a.x, a.y}) > 0;
    }
    int half() const {
        return y < 0 || (y == 0 && x < 0);
    }
};

int N;
ll H;
ang a[100005];

bool solve(ll t) {
    vt<ang> v;
    rep(i,0,N) {
        if (a[i].t >= H-t) {
            v.pb(a[i]);
        }
    }
    int n = sz(v);
    if (n < 3) return 0;
    // cerr << "t: " << t << " n: " << n << endl;
    // cout << "Filtered angles:" << endl;
    // rep(i,0,n) {
    //     cout << v[i].x << " " << v[i].y << " " << v[i].t << endl;
    // }
    int l = 0, r = 0;
    rep(i,0,n) {
        if (l == i) l = (l+1)%n;
        while (cross({v[i].x, v[i].y}, {v[(l+1)%n].x, v[(l+1)%n].y}) > 0) {
            // cout << "Moving l: " << l << " to " << (l+1)%n << endl;
            l = (l+1)%n;
        }
        int tmp = r;
        bool bad = 0;
        while (cross({v[i].x, v[i].y}, {v[r].x, v[r].y}) >= 0) {
            r = (r+1)%n;
            if (tmp == r) {
                bad = 1;
                break;
            }
        }
        bad |= cross({v[i].x, v[i].y}, {v[l].x, v[l].y}) <= 0;
        if (!bad && cross({v[l].x, v[l].y}, {v[r].x, v[r].y}) > 0) {
            // cout << "Found valid configuration for t = " << t << endl;
            // cout << "l: " << l << " r: " << r << endl;
            // cout << "v[l]: (" << v[l].x << ", " << v[l].y << ") t: " << v[l].t << endl;
            // cout << "v[r]: (" << v[r].x << ", " << v[r].y << ") t: " << v[r].t << endl;
            // cout << "v[i]: (" << v[i].x << ", " << v[i].y << ") t: " << v[i].t << endl;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N;
    double h; cin >> h;
    H = round(h*100);
    rep(i,0,N) {
        double x, y, t; cin >> x >> y >> t;
        ll xx = round(x*100), yy = round(y*100), tt = round(t*100);
        a[i] = {xx, yy, tt};
    }
    double x, y; cin >> x >> y;
    ll X = round(x*100), Y = round(y*100);
    rep(i,0,N) {
        a[i].x -= X;
        a[i].y -= Y;
    }
    sort(a, a+N);
    // cout << "Sorted angles:" << endl;
    // rep(i,0,N) {
    //     cout << a[i].x << " " << a[i].y << " " << a[i].t << endl;
    // }
    ll l = 0, r = 2e11+1;
    while (l < r) {
        ll m = (l+r)/2;
        if (solve(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (l == 2e11+1) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(10) << l/100.0 << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}