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

int T, N;
int a[200005];
ll M = 16777216;

ll op(ll x) {
    x = ((x*64) ^ x) % M;
    x = ((x/32) ^ x) % M;
    x = ((x*2048) ^ x) % M;
    return x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto start = chrono::high_resolution_clock::now();
    // N = 4;
    N = 2037;
    umap<ll,ll> mp;
    rep(i,0,N) {
        ll x; cin >> x;
        vt<ll> v;
        vt<ll> v2;
        uset<ll> s;
        rep(j,0,2000) {
            ll y = op(x);
            ll d = y%10 - x%10 + 9;
            v.pb(d);
            v2.pb(y%10);
            x = y;
        }
        ll h = v[0]*19*19*19+v[1]*19*19+v[2]*19+v[3];
        s.insert(h);
        mp[h]+=v2[0];
        rep(j,4,2000) {
            h -= v[j-4]*19*19*19;
            h *= 19;
            h += v[j];
            if (s.count(h)) continue;
            s.insert(h);
            mp[h]+=v2[j];
        }
    }
    ll ans = 0;
    for(auto i:mp) {
        ckmax(ans,i.se);
    }
    cout << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cerr << "Time: " << elapsed.count() << endl;
    return 0;
}