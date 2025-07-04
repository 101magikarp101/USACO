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

int T, N;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        rep(i,0,N) cin >> a[i];
        int l = 0, r = N-1;
        vt<pii> ans;
        l = 0, r = N-1;
        while (l<=r) {
            while (l < N && a[l] == 2) l++;
            while (r >= 0 && a[r] == 2) r--;
            if (l > r) break;
            if (a[l] == 1 && a[r] == 0) {
                swap(a[l], a[r]);
                ans.pb({l+1, r+1});
            } else if (a[l] == 0 && a[r] == 0) {
                l++;
            } else if (a[l] == 1 && a[r] == 1) {
                r--;
            } else {
                l++;
                r--;
            }
        }
        l = 0, r = N-1;
        while (l<=r) {
            while (l < N && a[l] == 0) l++;
            while (r >= 0 && a[r] == 0) r--;
            if (l > r) break;
            if (a[l] == 2 && a[r] == 1) {
                swap(a[l], a[r]);
                ans.pb({l+1, r+1});
            } else if (a[l] == 1 && a[r] == 1) {
                l++;
            } else if (a[l] == 2 && a[r] == 2) {
                r--;
            } else {
                l++;
                r--;
            }
        }
        cout << sz(ans) << endl;
        each(i,ans) cout << i.x << ' ' << i.y << endl;
    }
    return 0;
}