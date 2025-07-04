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

struct state {
    int x, y, i;
    bool operator<(const state &a) const { 
        if (x == a.x) {
            return y < a.y;
        } else {
            return x < a.x;
        }
    }
};

bool comp(state a, state b) {
    if (a.y == b.y) {
        return a.x < b.x;
    } else {
        return a.y < b.y;
    }
}

int T, N;
state a[200005];
int l[200005], r[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        rep(i,0,N) {
            cin >> a[i].x >> a[i].y;
            a[i].i = i;
            l[i] = r[i] = 0;
        }
        mset<state> s;
        sort(a,a+N,[](state a, state b) {
            return a.y == b.y ? a.x > b.x : a.y < b.y;
        });
        rep(i,0,N) {
            while (!s.empty() && s.rbegin()->x >= a[i].x) {
                auto &t = *s.rbegin();
                r[t.i] = a[i].y-t.y;
                s.erase(prev(s.end()));
            }
            s.insert(a[i]);
        }
        mset<state, decltype(&comp)> s2(comp);
        sort(a,a+N,[](state a, state b) {
            return a.x == b.x ? a.y < b.y : a.x > b.x;
        });
        rep(i,0,N) {
            while (!s2.empty() && s2.begin()->y <= a[i].y) {
                auto &t = *s2.begin();
                l[t.i] = t.x-a[i].x;
                s2.erase(s2.begin());
            }
            s2.insert(a[i]);
        }
        map<pii,int> m;
        rep(i,0,N) {
            m[{a[i].x,a[i].y}]++;
        }
        rep(i,0,N) {
            if (m[{a[i].x,a[i].y}] > 1) {
                l[a[i].i] = r[a[i].i] = 0;
            }
        }
        rep(i,0,N) {
            cout << l[i]+r[i] << endl;
        }
    }
    return 0;
}