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
#define rrep(i,a,b) for(int i=a;i>=b;i--)
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

struct dat {
    bool k;
    vt<int> v;
};

int T, N;
vt<dat> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // N = 5;
    N = 4000/8;
    rep(i,0,N) {
        bool key = 1;
        vt<int> temp;
        vt<vt<char>> c(7, vt<char>(5));
        rep(j,0,7) {
            rep(k,0,5) {
                cin >> c[j][k];
            }
        }
        rep(k,0,5) {
            key &= (c[6][k] == '#');
        }
        rep(k,0,5) {
            int cnt = 0;
            rep(j,1,6) {
                cnt += (c[j][k] == '#');
            }
            temp.pb(cnt);
        }
        v.pb({key, temp});
    }
    rep(i,0,N) {
        cout << "v: ";
        each(j,v[i].v) {
            cout << j << " ";
        }
        cout << "k: " << v[i].k << endl;
    }
    int ans = 0;
    rep(i,0,N) {
        if (v[i].k) continue;
        rep(j,0,N) {
            if (!v[j].k) continue;
            bool g = 1;
            rep(k,0,5) {
                g &= (v[i].v[k]+v[j].v[k] <= 5);
            }
            // cout << "i: " << i << " j: " << j << " g: " << g << endl;
            ans += g;
        }
    }
    cout << ans << endl;
    return 0;
}