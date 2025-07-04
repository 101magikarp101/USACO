#include <bits/stdc++.h>
#include <regex>
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
vt<string> v = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    N = 1000;
    int ans = 0;
    rep(i,0,N) {
        string s; cin >> s;
        bool g = 0;
        rep(j,0,sz(s)) {
            rep(k,0,9) {
                if (s.substr(j,sz(v[k]))==v[k]) {
                    ans += (k+1)*10;
                    g = 1;
                    break;
                }
            }
            if (g) break;
            if (s[j]<='9') {
                ans += (s[j]-'0')*10;
                break;
            }
        }
        g = 0;
        rrep(j,sz(s)-1,0) {
            rep(k,0,9) {
                if (s.substr(j,sz(v[k]))==v[k]) {
                    ans += (k+1);
                    g = 1;
                    break;
                }
            }
            if (g) break;
            if (s[j]<='9') {
                ans += s[j]-'0';
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}