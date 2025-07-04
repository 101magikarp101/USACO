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

int T, N, Q;
int a[100005], b[100005], c[100005];

void op1() {
    rep(i,1,N+1) {
        c[i] = a[b[a[i]]];
    }
    rep(i,1,N+1) {
        a[i] = c[i];
    }
}

void op2() {
    rep(i,1,N+1) {
        c[i] = b[a[b[i]]];
    }
    rep(i,1,N+1) {
        b[i] = c[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N;
    rep(i,1,N+1) cin >> a[i];
    rep(i,1,N+1) cin >> b[i];
    shuffle(a+1, a+N+1, default_random_engine(chrono::steady_clock::now().time_since_epoch().count()));
    shuffle(b+1, b+N+1, default_random_engine(chrono::steady_clock::now().time_since_epoch().count()));
    cout << "start: " << endl;
    rep(i,1,N+1) {
        cout << a[i] << ' ';
    }
    cout << endl;
    rep(i,1,N+1) {
        cout << b[i] << ' ';
    }
    cout << endl;
    cin >> Q;
    while (Q--) {
        int op; cin >> op;
        if (op == 1) {
            op1();
        } else {
            op2();
        }
        cout << "result: " << endl;
        rep(i,1,N+1) {
            cout << a[i] << ' ';
        }
        cout << endl;
        rep(i,1,N+1) {
            cout << b[i] << ' ';
        }
        cout << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}