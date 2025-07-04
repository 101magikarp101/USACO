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
#define repl(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define rrepl(i,a,b) for(ll i=a;i>=b;i--)
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

int ad(int a, int b, int m) {
    a+=b;
    if (a>=m) a-=m;
    return a;
}

int mul(int a, int b, int m) {
    return (int)((a*1LL*b)%m);
}

int N, K;
int a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> K;
    rep(i,0,N) cin >> a[i];
    umap<int,int> cnt;
    set<pii> s;
    auto add = [&](int x) {
        if (s.empty()) {
            s.insert({x, x});
            return;
        }
        auto itr = s.lower_bound({x, 0});
        auto itl = prev(itr);
        bool mergel = (itr != s.begin() && itl->y+1 == x);
        bool merger = (itr != s.end() && itr->x-1 == x);
        if (mergel && merger) {
            s.erase(itl);
            s.erase(itr);
            s.insert({itl->x, itr->y});
        } else if (mergel) {
            s.erase(itl);
            s.insert({itl->x, x});
        } else if (merger) {
            s.erase(itr);
            s.insert({x, itr->y});
        } else {
            s.insert({x, x});
        }
    };

    auto remove = [&](int x) {
        auto it = s.upper_bound({x, INT_MAX});
        it--;
        
        if (it->x == x && it->y == x) {
            s.erase(it);
        } else if (it->x == x) {
            int y = it->y;
            s.erase(it);
            s.insert({x+1, y});
        } else if (it->y == x) {
            int y = it->x;
            s.erase(it);
            s.insert({y, x-1});
        } else {
            int l = it->x, r = it->y;
            s.erase(it);
            s.insert({l, x-1});
            s.insert({x+1, r});
        }
    };

    auto mex = [&]() {
        if (s.empty()) return 0;
        if (s.begin()->x > 0) return 0;
        return s.begin()->y + 1;
    };
    rep(i,0,K) {
        if (++cnt[a[i]] == 1) {
            add(a[i]);
        }
    }
    cout << mex() << ' ';
    rep(i,K,N) {
        if (--cnt[a[i-K]] == 0) {
            remove(a[i-K]);
        }
        if (++cnt[a[i]] == 1) {
            add(a[i]);
        }
        cout << mex() << ' ';
    }
    cout << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}