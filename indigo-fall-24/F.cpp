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

int N;
ll a[1000005];
ll lift[1000005][21];
ll dist[1000005][21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    rep(i,0,N) cin >> a[i];
    rep(i,0,N) {
        lift[i][0] = (i+a[i])%N;
        dist[i][0] = a[i];
    }
    rep(j,1,21) {
        rep(i,0,N) {
            lift[i][j] = lift[lift[i][j-1]][j-1];
            dist[i][j] = dist[i][j-1]+dist[lift[i][j-1]][j-1];
        }
    }
    ll ans = N;
    rep(i,0,N) {
        ll cur = i;
        ll d = 0;
        ll tot = 0;
        for (int j = 20; j >= 0; j--) {
            if (d+dist[cur][j] < N-1) {
                d += dist[cur][j];
                cur = lift[cur][j];
                tot += (1<<j);
            }
        }
        tot++;
        ans = min(ans,tot);
    }
    cout << ans << endl;
    return 0;
}