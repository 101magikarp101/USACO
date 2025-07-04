#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

struct square {
    int x, y, s;
};

bool bet(int a, int b, int c) {
    return a <= b && b <= c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    square a, b; cin >> a.x >> a.y >> a.s >> b.x >> b.y >> b.s;
    if (bet(a.x, b.x, a.x+a.s) && bet(b.y, a.y, b.y+b.s)) {
        cout << "YES" << endl;
    } else if (bet(a.x, b.x+b.s, a.x+a.s) && bet(b.y, a.y, b.y+b.s)) {
        cout << "YES" << endl;
    } else if (bet(a.x, b.x, a.x+a.s) && bet(b.y, a.y+a.s, b.y+b.s)) {
        cout << "YES" << endl;
    } else if (bet(a.x, b.x+b.s, a.x+a.s) && bet(b.y, a.y+a.s, b.y+b.s)) {
        cout << "YES" << endl;
    } else if (bet(a.y, b.y, a.y+a.s) && bet(b.x, a.x, b.x+b.s)) {
        cout << "YES" << endl;
    } else if (bet(a.y, b.y+b.s, a.y+a.s) && bet(b.x, a.x, b.x+b.s)) {
        cout << "YES" << endl;
    } else if (bet(a.y, b.y, a.y+a.s) && bet(b.x, a.x+a.s, b.x+b.s)) {
        cout << "YES" << endl;
    } else if (bet(a.y, b.y+b.s, a.y+a.s) && bet(b.x, a.x+a.s, b.x+b.s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}