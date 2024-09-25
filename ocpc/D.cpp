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

int T, N;
int a[100005], b[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) cin >> a[i];
        for (int i = 0; i < N; i++) cin >> b[i];
        bool good = 1;
        int n = -1;
        for (int i = 0; i < N; i++) {
            int d = b[i] - a[i];
            if (d == 0) {
                good = 0;
                n = a[i];
                break;
            }
        }
        if (good) {
            cout << "YES" << endl;
            for (int i = 0; i < N; i++) {
                cout << b[i]/2*2 << ' ';
            }
            cout << endl;
            continue;
        }
        vt<int> f;
        for (int i = 1; i*i <= n; i++) {
            if (n%i == 0) {
                if (i!=1) f.pb(i);
                if (i*i != n) f.pb(n/i);
            }
        }
        int ans = -1;
        for (int i = 0; i < sz(f); i++) {
            int x = f[i];
            bool good = 1;
            for (int j = 0; j < N; j++) {
                int l = (a[j]+x-1)/x*x;
                int r = b[j]/x*x;
                if (l > r) {
                    good = 0;
                    break;
                }
            }
            if (good) {
                ans = x;
                break;
            }
        }
        if (ans == -1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < N; i++) {
                cout << b[i]/ans*ans << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}