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
    bool operator!=(const pii &a) const { return x != a.x && y != a.y; }
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
    bool operator!=(const pll &a) const { return x != a.x && y != a.y; }
    pll operator+(const pll &a) const { return {x+a.x, y+a.y}; }
    pll operator-(const pll &a) const { return {x-a.x, y-a.y}; }
    pll operator*(const ll &a) const { return {x*a, y*a}; }
    pll operator/(const ll &a) const { return {x/a, y/a}; }
};

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

int N, M, Q;
ll a[200005], b[200005];
set<ll> as, bs;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> Q;
    ll A = 0, B = 0;
    rep(i,0,N) {
        cin >> a[i];
        A += a[i];
        as.insert(a[i]);
    }
    rep(i,0,M) {
        cin >> b[i];
        B += b[i];
        bs.insert(b[i]);
    }
    while (Q--) {
        ll x; cin >> x;
        ll t = A*B-x;
        // cout << "t: " << t << endl;
        ll tar = A*B-t;
        // cout << "tar: " << tar << endl;
        if (tar == 0) {
            ll ta = A, tb = B;
            if (as.count(ta) || bs.count(tb)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (tar > 0) {
            bool ok = 0;
            for (ll i = 1; i*i <= tar; i++) {
                if (tar%i == 0) {
                    if (as.count(i+A) && bs.count(tar/i+B)) {
                        cout << "YES" << endl;
                        ok = 1;
                        break;
                    }
                    if (as.count(-i+A) && bs.count(-tar/i+B)) {
                        cout << "YES" << endl;
                        ok = 1;
                        break;
                    }
                    if (as.count(tar/i+A) && bs.count(i+B)) {
                        cout << "YES" << endl;
                        ok = 1;
                        break;
                    }
                    if (as.count(-tar/i+A) && bs.count(-i+B)) {
                        cout << "YES" << endl;
                        ok = 1;
                        break;
                    }
                }
            }
            if (!ok) cout << "NO" << endl;
        } else {
            tar = -tar;
            bool ok = 0;
            for (ll i = 1; i*i <= tar; i++) {
                if (tar%i == 0) {
                    if (as.count(i+A) && bs.count(-tar/i+B)) {
                        cout << "YES" << endl;
                        ok = 1;
                        break;
                    }
                    if (as.count(-i+A) && bs.count(tar/i+B)) {
                        cout << "YES" << endl;
                        ok = 1;
                        break;
                    }
                    if (as.count(tar/i+A) && bs.count(-i+B)) {
                        cout << "YES" << endl;
                        ok = 1;
                        break;
                    }
                    if (as.count(-tar/i+A) && bs.count(i+B)) {
                        cout << "YES" << endl;
                        ok = 1;
                        break;
                    }
                }
            }
            if (!ok) cout << "NO" << endl;
        }
    }
    return 0;
}