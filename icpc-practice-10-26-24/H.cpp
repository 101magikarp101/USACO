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

int N = 500000000;
const ll M = 1LL<<40;
map<ll,ll> s;
ll res[355];
ll vals[355];
ll res2[185];
ll vals2[185];

ll h(ll x) {
    return (x + (x>>20) + 12345)%M;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << 532254519-350125310 << endl;
    ll x = 1611516670LL;
    s[x] = 0;
    for (int i = 1; i <= 350; i++) {
        for (int j = 0; j < 1000000; j++) {
            x = h(x);
            res[i] += (x%2==0);
        }
        vals[i] = x;
    }
    for (int i = 350000001; i <= 350125310; i++) {
        x = h(x);
        res[351] += (x%2==0);
    }
    vals[351] = x;
    cout << "res: " << endl;
    cout << "{";
    for (int i = 1; i <= 351; i++) {
        cout << res[i] << ",";
    }
    cout << "}" << endl;
    cout << "vals: " << endl;
    cout << "{";
    for (int i = 1; i <= 351; i++) {
        cout << vals[i] << ",";
    }
    cout << "}" << endl;
    for (int i = 1; i <= 182; i++) {
        for (int j = 0; j < 1000000; j++) {
            x = h(x);
            res2[i] += (x%2==0);
        }
        vals2[i] = x;
    }
    for (int i = 182000001; i <= 182129209; i++) {
        x = h(x);
        res2[183] += (x%2==0);
    }
    vals2[183] = x;
    cout << "res2: " << endl;
    cout << "{";
    for (int i = 1; i <= 183; i++) {
        cout << res2[i] << ",";
    }
    cout << "}" << endl;
    cout << "vals2: " << endl;
    cout << "{";
    for (int i = 1; i <= 183; i++) {
        cout << vals2[i] << ",";
    }
    cout << "}" << endl;
    return 0;
}