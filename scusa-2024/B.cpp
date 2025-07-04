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

int calc(int x, int y) {
    if (x == 0) return 0;
    else if (y == 2024) return 1;
    else if (x == 2024) return 2;
    else return 3;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if (x1==0&&y1==0) {
        cout << !(x2==2024&&y2==2024) << endl;
    } else if (x1==2024&&y1==0) {
        cout << !(x2==0&&y2==2024) << endl;
    } else if (x1==0&&y1==2024) {
        cout << !(x2==2024&&y2==0) << endl;
    } else if (x1==2024&&y1==2024) {
        cout << !(x2==0&&y2==0) << endl;
    } else if (x2==0&&y2==0) {
        cout << !(x1==2024&&y1==2024) << endl;
    } else if (x2==2024&&y2==0) {
        cout << !(x1==0&&y1==2024) << endl;
    } else if (x2==0&&y2==2024) {
        cout << !(x1==2024&&y1==0) << endl;
    } else if (x2==2024&&y2==2024) {
        cout << !(x1==0&&y1==0) << endl;
    } else {
        cout << 2 << endl;
    }
    return 0;
}