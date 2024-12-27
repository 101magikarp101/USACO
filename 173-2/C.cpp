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

pii solve(int l, int r) {
    set<int> s;
    s.insert(0);
    int sum = 0;
    int mi = 0;
    int ma = 0;
    rep(i,l,r+1) {
        sum += a[i];
        ckmin(mi, sum-*s.rbegin());
        ckmax(ma, sum-*s.begin());
        s.insert(sum);
    }
    return {mi, ma};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        int hm = -1;
        rep(i,0,N) {
            cin >> a[i];
            if (abs(a[i])!=1) {
                hm = i;
            }
        }
        if (hm == -1) {
            pii res = solve(0, N-1);
            set<int> s;
            s.insert(0);
            rep(i,res.x,res.y+1) {
                s.insert(i);
            }
            cout << sz(s) << endl;
            each(i,s) {
                cout << i << " ";
            }
            cout << endl;
            continue;
        }
        pii left = solve(0, hm-1);
        pii right = solve(hm+1, N-1);
        set<int> s;
        s.insert(0);
        rep(i,left.x,left.y+1) {
            s.insert(i);
        }
        rep(i,right.x,right.y+1) {
            s.insert(i);
        }
        pii l = {0,0};
        int sum = 0;
        rrep(i,hm-1,0) {
            sum += a[i];
            ckmin(l.x, sum);
            ckmax(l.y, sum);
        }
        pii r = {0,0};
        sum = 0;
        rep(i,hm+1,N) {
            sum += a[i];
            ckmin(r.x, sum);
            ckmax(r.y, sum);
        }
        int mi = l.x+r.x;
        int ma = l.y+r.y;
        rep(i,mi,ma+1) {
            s.insert(i+a[hm]);
        }
        cout << sz(s) << endl;
        each(i,s) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}