#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define M_PI 3.1415926535897932384626433
#define vt vector
template <class T> using vvt = vt<vt<T>>;
template <class T> using vvvt = vt<vvt<T>>;
template <class T> using vvvvt = vt<vvvt<T>>;
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

int T, N;

struct vec {
    double x, y, z;
    vec operator+(const vec &a) const { return {x+a.x, y+a.y, z+a.z}; }
    vec operator-(const vec &a) const { return {x-a.x, y-a.y, z-a.z}; }
    vec operator*(const double &a) const { return {x*a, y*a, z*a}; }
    vec operator/(const double &a) const { return {x/a, y/a, z/a}; }
    friend istream& operator>>(istream &is, vec &v) {
        return is >> v.x >> v.y >> v.z;
    }
    friend ostream& operator<<(ostream &os, const vec &v) {
        return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    }
};

double dot(const vec &a, const vec &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec cross(const vec &a, const vec &b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

vec norm(const vec &v) {
    double len = sqrtl(dot(v, v));
    return {v.x / len, v.y / len, v.z / len};
}

double angle(const vec &a, const vec &b) {
    double cos_theta = dot(a, b) / (sqrtl(dot(a, a)) * sqrtl(dot(b, b)));
    cos_theta = max(-1.0, min(1.0, cos_theta));
    return acosl(cos_theta);
}

double dist(const vec &a, const vec &b) {
    return angle(a, b);
}

double distcirc(const vec &a, const vec &n, const vec &m) {
    vec o = cross(n, m);
    double ang = angle(a, o);
    ang = min(ang, M_PI - ang);
    ang = M_PI/2.0 - ang;
    return ang;
}

bool side(const vec &a, const vec &u, const vec &v) {
    vec proj = u*dot(u,v)/dot(u,u); 
    vec pole = v-proj;
    double th = angle(a, pole);
    return th <= M_PI / 2.0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cout << fixed << setprecision(10);

    cin >> T;
    while (T--) {
        double r; vec a, u, v; cin >> r >> a >> u >> v;
        a = norm(a);
        u = norm(u);
        v = norm(v);
        bool bu = side(a, u, v);
        bool bv = side(a, v, u);
        double du = dist(a, u);
        double dv = dist(a, v);
        double ans = min(du, dv);
        if (bu&&bv) {
            ans = min(ans, distcirc(a, u, v));
        } else if (!bu&&!bv) {
            ans = min(ans, M_PI-distcirc(a, u, v));
        }
        ans *= r;
        cout << ans << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}