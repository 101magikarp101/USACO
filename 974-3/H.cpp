#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
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

int T, N, Q;
int a[200005];
ull b[200005];
set<int> s;
map<int, ull> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<ull> dis(1, ULLONG_MAX);
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        for (int x : s) {
            m[x] = dis(gen);
        }
        b[0] = m[a[0]];
        for (int i = 1; i < N; i++) {
            b[i] = b[i-1]^m[a[i]];
        }
        while (Q--) {
            int x, y; cin >> x >> y;
            x--; y--;
            ull res = b[y];
            if (x > 0) res ^= b[x-1];
            cout << (res==0?"YES":"NO") << endl;
        }
    }
    return 0; 
}