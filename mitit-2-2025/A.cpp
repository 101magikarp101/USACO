#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define MO N
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

template <class T> class BIT {
//     MUST be 1-indexed
public:
    vector<T> bit;
    vector<T> a;
    int size;

    BIT(int n) {
        size = n;
        bit.resize(n + 1);
        a.resize(n + 1);
    }

    void add(int i, T x) {
        a[i] += x;
        for (int k = i; k <= size; k += k & -k) {
            bit[k] += x;
        }
    }

    void set(int i, T x) {
        add(i, x - a[i]);
    }

    T sum(int i) {
        if (i <= 0) return 0;
        if (i > size) i = size;
        T s = 0;
        for (int k = i; k > 0; k -= k & -k) {
            s += bit[k];
        }
        return s;
    }

    // [l,r]
    T query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int T, N;
pll a[500005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> MO;
        rep(i,0,N) cin >> a[i].x;
        rep(i,0,N) cin >> a[i].y;
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        // {diff, tot}
        ll tot = 0;
        rep(i,0,N) {
            pq.push({a[i].y-a[i].x, a[i].y});
        }
        bool ok = 1;
        while (!pq.empty()) {
            auto [d, t] = pq.top();
            // cout << "d: " << d << " t: " << t << endl;
            pq.pop();
            if (d-tot > 0) {
                ok = 0;
                break;
            }
            tot += t-d;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}