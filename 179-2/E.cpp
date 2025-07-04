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

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

int T, N, Q;
set<int> hm[3][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> N >> Q;
        rep(i,0,3) rep(j,0,3) hm[i][j].clear();
        string s; cin >> s;
        rep(i,0,Q) {
            char x, y; cin >> x >> y;
            hm[x-'a'][y-'a'].insert(i);
        }
        rep(i,0,N) {
            if (s[i] == 'a') continue;
            else if (s[i] == 'b') {
                if (!hm[1][0].empty()) {
                    hm[1][0].erase(hm[1][0].begin());
                    s[i] = 'a';
                } else if (!hm[1][2].empty()) {
                    int j = *hm[1][2].begin();
                    auto it = hm[2][0].lower_bound(j);
                    if (it != hm[2][0].end()) {
                        hm[1][2].erase(j);
                        hm[2][0].erase(it);
                        s[i] = 'a';
                    }
                }
            } else {
                if (!hm[2][0].empty()) {
                    hm[2][0].erase(hm[2][0].begin());
                    s[i] = 'a';
                } else if (!hm[2][1].empty()) {
                    int j = *hm[2][1].begin();
                    auto it = hm[1][0].lower_bound(j);
                    if (it != hm[1][0].end()) {
                        hm[2][1].erase(j);
                        hm[1][0].erase(it);
                        s[i] = 'a';
                    } else {
                        hm[2][1].erase(j);
                        s[i] = 'b';
                    }
                }
            }
        }
        cout << s << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}