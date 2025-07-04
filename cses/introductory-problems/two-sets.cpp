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

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    if (N%4==1 || N%4==2) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vt<int> a, b;
    if (N%4==0) {
        for (int i = 1; i <= N; i++) {
            if (i%4==1 || i%4==0) a.pb(i);
            else b.pb(i);
        }
    } else {
        a.pb(1);
        a.pb(2);
        b.pb(3);
        for (int i = 4; i <= N; i++) {
            if (i%4==3 || i%4==0) a.pb(i);
            else b.pb(i);
        }
    }
    cout << sz(a) << endl;
    for (int i : a) cout << i << " ";
    cout << endl;
    cout << sz(b) << endl;
    for (int i : b) cout << i << " ";
    cout << endl;
    return 0;
}