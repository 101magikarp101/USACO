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

int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

void tell(int k) {
    cout << "! " << k << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        int x1 = ask(1,N/4);
        int x2 = ask(N/4+1,N/2);
        int x3 = (x1!=x2? ask(N/2+1,N) : ask(1,N/2));
        bool side = x1==x2;
        bool small = x3;
        // cout << "side: " << side << " small: " << small << endl;
        
        if (small) {
            int l = 2, r = N/2;
            while (l < r) {
                int m = (l+r)/2;
                int res = (side ? ask(1,m) : ask(N/2+1,N/2+m));
                if (res) {
                    r = m;
                } else {
                    l = m+1;
                }
            }
            tell(l);
        } else {
            int l = N/2+1, r = N;
            while (l < r) {
                int m = (l+r)/2;
                int res = (side ? ask(N-m+1,N) : ask(1,m));
                if (!res) {
                    r = m;
                } else {
                    l = m+1;
                }
            }
            tell(l);
        }
    }
    return 0;
}