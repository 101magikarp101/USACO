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

int T, N, M;
ll L;
pll a[200005];
pll b[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M >> L;
        rep(i,0,N) {
            cin >> a[i].x >> a[i].y;
        }
        rep(i,0,M) {
            cin >> b[i].x >> b[i].y;
        }
        ll cur = 1;
        int r = -1;
        mset<ll, greater<ll>> s;
        int ans = 0;
        bool good = 1;
        rep(i,0,N) {
            ll d = a[i].y-a[i].x+2;
            while (r < M-1 && b[r+1].x < a[i].x) {
                r++;
                s.insert(b[r].y);
            }
            while (!s.empty() && cur < d) {
                ans++;
                cur += *s.begin();
                s.erase(s.begin());
            }
            if (cur < d) {
                good = 0;
                break;
            }
        }
        if (good) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}