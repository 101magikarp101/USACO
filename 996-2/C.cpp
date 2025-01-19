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

int T, N, M;
ll a[1005][1005];
ll r[1005], c[1005], r1[1005], c1[1005];

pii dir(char c) {
    if (c == 'D') return {1,0};
    else return {0,1};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> N >> M;
        rep(i,0,N) r[i] = 0, r1[i] = 0;
        rep(i,0,M) c[i] = 0, c1[i] = 0;
        string s; cin >> s;
        rep(i,0,N) rep(j,0,M) {
            cin >> a[i][j];
        }
        rep(i,0,N) {
            rep(j,0,M) {
                r[i] += a[i][j];
                c[j] += a[i][j];
            }
        }
        vt<pii> path;
        pii pos = {0,0};
        path.pb(pos);
        rep(i,0,sz(s)) {
            pos = pos + dir(s[i]);
            path.pb(pos);
        }
        each(x,path) {
            r1[x.x]++;
            c1[x.y]++;
        }
        each(x,path) {
            if (r1[x.x] == 1) {
                a[x.x][x.y] = -r[x.x];
                c[x.y] += a[x.x][x.y];
                r1[x.x]--;
                c1[x.y]--;
            } else {
                a[x.x][x.y] = -c[x.y];
                r[x.x] += a[x.x][x.y];
                r1[x.x]--;
                c1[x.y]--;
            }
        }
        rep(i,0,N) {
            rep(j,0,M) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}