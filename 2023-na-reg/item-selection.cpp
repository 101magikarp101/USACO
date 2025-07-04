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

int N, M, S, P, Q;
bool a[1005], b[1005];
bool fix[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> S >> P >> Q;
    rep(i,0,P) {
        int x; cin >> x;
        a[x] = 1;
    }
    rep(i,0,Q) {
        int x; cin >> x;
        b[x] = 1;
    }
    int sec = (N+M-1)/M;
    int tot = 0;
    rep(i,1,sec+1) {
        int res1 = 0, res2 = 1, res3 = 1;
        rep(j,(i-1)*M+1,min(N,i*M)+1) {
            res1 += a[j]^b[j];
            res2 += b[j];
            res3 += !b[j];
            fix[i] |= a[j]^b[j];
        }
        tot += min({res1,res2,res3});
    }
    int l = 0;
    for (int i = 1; i <= S-1; i++) {
        if (fix[i]) {
            l = S-i;
            break;
        }
    }
    int r = 0;
    for (int i = sec; i >= S+1; i--) {
        if (fix[i]) {
            r = i-S;
            break;
        }
    }
    // cout << "l: " << l << " r: " << r << endl;
    int travel = l+r+min(l,r);
    // cout << "tot: " << tot << " travel: " << travel << endl;
    cout << tot+travel << endl;
    return 0;
}