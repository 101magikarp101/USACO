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

int T, N, Q;
int a[200005];
int b[200005];
int ans = 0;

int chk(int x) {
    return a[x]==1&&a[x+1]==1&&a[x+2]==0&&a[x+3]==0;
}

void upd(int x) {
    for (int i = x-3; i <= x; i++) {
        if (i < 0) continue;
        if (i+3 >= N) continue;
        ans-=b[i];
        b[i] = 0;
        b[i] = chk(i);
        ans+=b[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        ans = 0;
        string s; cin >> s;
        N = sz(s);
        for (int i = 0; i < sz(s); i++) {
            a[i] = s[i] - '0';
            b[i] = 0;
        }
        for (int i = 0; i < sz(s); i++) {
            upd(i);
        }
        cin >> Q;
        while (Q--) {
            int x, y; cin >> x >> y;
            a[x-1] = y;
            upd(x-1);
            cout << (ans?"YES":"NO") << endl;
        }
    }
    return 0;
}