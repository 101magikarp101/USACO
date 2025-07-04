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

int N, Q;
int a[200005];
int r[200005];
const int M = 18;
int up[200005][M];
ll p[200005], upw[200005][M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> Q;
    rep(i,0,N) cin >> a[i];
    p[0] = a[0];
    rep(i,1,N) p[i] = p[i-1] + a[i];
    stack<int> st;
    rrep(i,N-1,0) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        r[i] = st.empty() ? N : st.top();
        up[i][0] = r[i];
        upw[i][0] = (ll)a[i] * (r[i] - i) - (p[r[i]-1] - (i ? p[i-1] : 0));
        st.push(i);
    }
    up[N][0] = N;
    upw[N][0] = 0;
    rep(j,1,M) {
        rep(i,0,N+1) {
            up[i][j] = up[up[i][j-1]][j-1];
            upw[i][j] = upw[i][j-1] + upw[up[i][j-1]][j-1];
        }
    }
    while (Q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        ll ans = 0;
        int x = l;
        rrep(i,M-1,0) {
            if (up[x][i] <= r) {
                ans += upw[x][i];
                x = up[x][i];
            }
        }
        ans += (ll)a[x] * (r - x + 1) - (p[r] - (x ? p[x-1] : 0));
        cout << ans << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}