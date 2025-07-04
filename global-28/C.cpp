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
int a[200005];

string xo(string s, string t) {
    string res = s;
    rep(i,0,sz(t)) {
        res[sz(s)-i-1] = (s[sz(s)-i-1] == t[sz(t)-i-1] ? '0' : '1');
    }
    return res;
}

struct sus {
    string s;
    int l, r;
    bool operator< (const sus &a) const {
        return s < a.s;
    }
    bool operator> (const sus &a) const {
        return s > a.s;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        string s; cin >> s;
        N = sz(s);
        int z = -1;
        rep(i,0,sz(s)) {
            if (s[i] == '0') {
                z = i;
                break;
            }
        }
        if (z == -1) {
            cout <<1<<" "<<N<<" "<<1<<" "<<1<<endl;
            continue;
        }
        int l = sz(s)-z;
        vt<sus> v;
        rep(i,0,z) {
            string t = s.substr(i,l);
            string x = xo(s,t);
            v.pb({x,i+1,i+l});
        }
        sort(all(v),greater<sus>());
        cout << 1 << " " << N << " " << v[0].l << " " << v[0].r << endl;
    }
    return 0;
}