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
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t; cin >> s >> t;
    double a = stod(s), b = stod(t);
    int b1 = 0;
    if (a == b) {
        b1 = 0;
    } else {
        b1 = (a < b) ? -1 : 1;
    }
    int i = s.find('.'), j = t.find('.');
    int x = stoi(s.substr(0, i)), y = stoi(t.substr(0, j));
    int z = stoi(s.substr(i+1)), w = stoi(t.substr(j+1));
    int b2 = 0;
    if (x == y) {
        if (z == w) {
            b2 = 0;
        } else {
            b2 = (z < w) ? -1 : 1;
        }
    } else {
        b2 = (x < y) ? -1 : 1;
    }
    if (b1 == b2) {
        if (b1 > 0) cout << s << endl;
        else cout << t << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}