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

int T, N, M;
ll a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        rep(i,1,N+1) cin >> a[i];
        int ans = 0;
        if (a[M]>0 && M>1) {
            ans++;
            a[M] = -a[M];
        }
        ll tar = 0;
        rep(i,1,M+1) tar += a[i];
        // cout << "tar: " << tar << endl;
        mset<pll,greater<pll>> s;
        ll sum = tar;
        rrep(i,M-1,1) {
            sum -= a[i+1];
            while (sum < tar) {
                auto [val, idx] = *s.begin();
                // cout << "val: " << val << " idx: " << idx << endl;
                s.erase(s.begin());
                a[idx] = -a[idx];
                ans++;
                tar += 2*a[idx];
            }
            if (a[i]>0) {
                s.insert({a[i],i});
            }
        }
        sum = tar;
        mset<pll> s2;
        rep(i,M+1,N+1) {
            // cout << "i: " << i << endl;
            sum += a[i];
            if (a[i]<0) {
                s2.insert({a[i],i});
            }
            while (sum < tar) {
                auto [val, idx] = *s2.begin();
                // cout << "sum: " << sum << " tar: " << tar << endl;
                // cout << "val: " << val << " idx: " << idx << endl;
                s2.erase(s2.begin());
                a[idx] = -a[idx];
                sum += 2*a[idx];
                // cout << "sum: " << sum << " tar: " << tar << endl;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}