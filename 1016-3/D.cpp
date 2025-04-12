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

ll T, N, Q;

ll solve1(ll x, ll y, ll dep) {
    if (dep == 0) return 1;
    ll res = solve1(x%(1LL<<(dep-1)), y%(1LL<<(dep-1)), dep-1);
    if (x < (1LL<<(dep-1)) && y < (1LL<<(dep-1))) return res;
    if (x >= (1LL<<(dep-1)) && y >= (1LL<<(dep-1))) return res + (1LL<<(2*dep-2));
    if (x >= (1LL<<(dep-1)) && y < (1LL<<(dep-1))) return res + (2LL<<(2*dep-2));
    if (x < (1LL<<(dep-1)) && y >= (1LL<<(dep-1))) return res + (3LL<<(2*dep-2));
}

pll solve2(ll n, ll dep) {
    if (dep == 0) return {1, 1};
    ll hm = (1LL<<(2*dep-2));
    pll res = solve2(n%hm, dep-1);
    if (n < hm) return res;
    if (n >= hm && n < 2*hm) return {res.x + (1LL<<(dep-1)), res.y + (1LL<<(dep-1))};
    if (n >= 2*hm && n < 3*hm) return {res.x + (1LL<<(dep-1)), res.y};
    if (n >= 3*hm && n < 4*hm) return {res.x, res.y + (1LL<<(dep-1))};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> N >> Q;
        while (Q--) {
            string s; cin >> s;
            if (s == "->") {
                ll x, y; cin >> x >> y;
                x--; y--;
                cout << solve1(x, y, N) << endl;
            } else {
                ll n; cin >> n;
                n--;
                pll ans = solve2(n, N);
                cout << ans.x << " " << ans.y << endl;
            }
        }
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}