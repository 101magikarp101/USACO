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

int T, N, M;

vt<string> split(string s, string delim) {
    vt<string> res;
    int start = 0;
    int end = s.find(delim);
    while (end != string::npos) {
        res.pb(s.substr(start, end-start));
        start = end+delim.size();
        end = s.find(delim, start);
    }
    res.pb(s.substr(start, end-start));
    return res;
}

bool safe(vt<int> &v) {
    int up = 0;
    rep(j,1,sz(v)) {
        int d = v[j]-v[j-1];
        if (abs(d) < 1 || abs(d) > 3) return 0;
        if (d == 0) return 0;
        if (d>0 && up<0) return 0;
        if (d<0 && up>0) return 0;
        if (d>0) up = 1;
        else up = -1;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // N = 6;
    N = 1000;
    int ans = 0;
    rep(i,0,N) {
        string s; getline(cin, s);
        vt<string> v = split(s, " ");
        vt<int> a;
        for (auto &i : v) a.pb(stoi(i));
        for (int i = 0; i < sz(v); i++) {
            vt<int> b = a;
            b.erase(b.begin()+i);
            if (safe(b)) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}