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

int T, N;
int d[200005];
pii a[200005], b[200005];

pii inter(pii x, pii y) {
    if (x.x > y.y || x.y < y.x) return {-1, -1};
    return {max(x.x, y.x), min(x.y, y.y)};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> N;
        rep(i,1,N+1) cin >> d[i];
        rep(i,1,N+1) {
            cin >> a[i].x >> a[i].y;
        }
        b[0] = {0,0};
        bool good = 1;
        rep(i,1,N+1) {
            if (d[i] != -1) {
                b[i] = inter({b[i-1].x+d[i], b[i-1].y+d[i]}, a[i]);
            } else {
                b[i] = inter({b[i-1].x, b[i-1].y+1}, a[i]);
            }
            // cout << "b[" << i << "] = " << b[i].x << ", " << b[i].y << endl;
            if (b[i].x == -1) {
                good = 0;
                break;
            }
        }
        if (!good) {
            cout << -1 << endl;
            continue;
        }
        vt<int> ans;
        int cur = b[N].y;
        rrep(i,N,1) {
            if (d[i] != -1) {
                cur -= d[i];
                ans.pb(d[i]);
            } else {
                if (b[i-1].x <= cur && cur <= b[i-1].y) {
                    ans.pb(0);
                } else {
                    ans.pb(1);
                    cur--;
                }
            }
        }
        reverse(all(ans));
        each(i, ans) {
            cout << i << " ";
        }
        cout << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}