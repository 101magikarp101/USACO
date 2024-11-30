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

int a[100005];

void tell(int x) {
    cout << x << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K = 66668;
    tell(K);
    a[0] = 1;
    a[100000] = 1;
    for (int i = 3; i <= 99999; i+=3) {
        a[i] = 1;
    }
    while (true) {
        int x; cin >> x;
        if (x == -1) break;
        if (a[x] == -1) tell(-1);
        else if (a[x] == 1) {
            if (x==0) {
                tell(1);
            } else if (x%3==1) {
                tell(x/3*2+2);
            } else if (x%3==2) {
                tell(x/3*2+2+(a[x-1]==1));
            } else {
                tell(x/3*2+1);
            }
        } else {
            tell(-1);
            int sec = (x+2)/3;
            a[sec*3-2] = 1;
            a[sec*3-1] = 1;
            a[sec*3] = 1;
            a[x-1] = 1;
            a[x] = -1;
            a[x+1] = 1;
        }
    }
    rep(i,1,100000) {
        if (a[i] == 0) {
            int sec = (i+2)/3;
            a[sec*3-2] = 1;
            a[sec*3-1] = 1;
            a[sec*3] = 1;
            a[i] = -1;
        }
    }
    rep(i,0,100001) {
        if (a[i] == 1) tell(i);
    }
    return 0;
}