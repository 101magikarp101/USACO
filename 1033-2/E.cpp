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

int T;
ll N, K;
ll a[200005], b[200005];

ll solve(ll n) {
    // cout << "solving for n = " << n << endl;
    ll ans = 0;
    ll cur = 0;
    rep(i,0,N) {
        cur += max(0LL, a[i] - n);
    }
    ans = cur;
    // cout << "cur = " << cur << endl;
    repl(i,1,N) {
        ll diff = max(0LL, min(a[i], n-K)-a[i-1]);
        ll need = diff*i;
        // cout << "i = " << i << ", diff = " << diff << ", need = " << need << ", cur = " << cur << endl;
        if (n-K <= a[i]) {
            if (cur > need) return -1;
        }
        if (cur <= need) {
            ll q = cur/i;
            ll r = cur%i;
            rrep(j,i-1,0) {
                b[j] = a[i-1] + q;
                if (r) {
                    b[j]++;
                    r--;
                }
            }
            rep(j,i,N) {
                b[j] = min(a[j], n);
            }
            return ans;
        } else {
            cur -= need;
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

    cin >> T;
    while (T--) {
        cin >> N >> K;
        rep(i,0,N) {
            cin >> a[i];
        }
        if (N == 1) {
            cout << a[0]*(a[0]+1)/2 << endl;
            continue;
        }
        sort(a, a+N);
        ll l = 1, r = 1e6;
        while (l < r) {
            ll m = (l+r)/2;
            if (solve(m) == -1) {
                l = m+1;
            } else {
                r = m;
            }
        }
        ll ans = solve(l);
        // cout << "l = " << l << ", ans = " << ans << endl;
        int left = 0;
        // cout << "final b: ";
        // rep(i,0,N) {
        //     cout << b[i] << " ";
        // }
        // cout << endl;
        rrep(i,N-1,0) {
            if (b[i] == l && b[left] < l-K) {
                b[i]--;
                if (b[left+1] > b[left]) {
                    b[left]++;
                    left = 0;
                } else {
                    b[left]++;
                    left++;
                }
                ans++;
            }
        }
        // cout << "final b after adjustment: ";
        // rep(i,0,N) {
        //     cout << b[i] << " ";
        // }
        // cout << endl;
        ans *= K;
        rep(i,0,N) {
            ans += b[i]*(b[i]+1)/2;
        }
        cout << ans << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}