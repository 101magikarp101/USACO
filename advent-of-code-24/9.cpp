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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto start = chrono::high_resolution_clock::now();
    string s; cin >> s;
    N = sz(s);
    vt<int> a;
    bool hm = 1;
    int cur = 0;
    vt<pii> b;
    rep(i,0,N) {
        if (hm) {
            b.pb({sz(a), s[i]-'0'});
            rep(j,0,s[i]-'0') {
                a.pb(cur);
            }
            cur++;
        } else {
            rep(j,0,s[i]-'0') {
                a.pb(-1);
            }
        }
        hm = !hm;
    }
    // rep(i,0,sz(a)) {
    //     if (a[i] == -1) {
    //         cout<<".";
    //     } else {
    //         cout<<a[i];
    //     }
    // }
    // cout << endl;
    rrep(i,sz(b)-1,0) {
        int idx = b[i].x;
        int cnt = b[i].y;
        int v = a[idx];
        for (int i = 0; i+cnt-1 < sz(a); i++) {
            if (i>=idx) continue;
            bool g = 1;
            for (int j = i; j < i+cnt; j++) {
                if (a[j] != -1) {
                    g = 0;
                    break;
                }
            }
            if (g) {
                for (int j = i; j < i+cnt; j++) {
                    a[j] = v;
                }
                for (int j = idx; j < idx+cnt; j++) {
                    a[j] = -1;
                }
                break;
            }
        }
    }
    ll ans = 0;
    rep(i,0,sz(a)) {
        if (a[i] == -1) {
            continue;
        }
        ans += (ll)(i)*a[i];
    }
    cout << ans << endl;
    // rep(i,0,sz(a)) {
    //     if (a[i] == -1) {
    //         cout<<".";
    //     } else {
    //         cout<<a[i];
    //     }
    // }
    // cout << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end-start);
    cerr << "Time: " << duration.count() << "ms" << endl;
    return 0;
}