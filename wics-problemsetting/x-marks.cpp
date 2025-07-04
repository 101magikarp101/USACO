#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define M_PI 3.14159265358979323846
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

struct state {
    int r;
    double x, y;
};

int N, Q;
pii a[200005];
state pre[200005]; // {start rotation, end position x, end position y}

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> Q;
    rep(i,0,N) {
        cin >> a[i].x >> a[i].y;
    }
    double x = 0, y = 0;
    int r = 90;
    rep(i,0,N) {
        if (a[i].x == 2) {
            double dx = a[i].y*cos(r*M_PI/180);
            double dy = a[i].y*sin(r*M_PI/180);
            x += dx;
            y += dy;
        }
        pre[i] = {r, x, y};
        if (a[i].x == 1) {
            r += a[i].y;
            r %= 360;
        }
    }
    rep(i,0,Q) {
        int l, r; cin >> l >> r;
        l--;
        r--;
        double dx = pre[r].x - (l == 0 ? 0 : pre[l-1].x);
        double dy = pre[r].y - (l == 0 ? 0 : pre[l-1].y);
        int dr = 90-pre[l].r;
        if (dr < 0) dr += 360;
        double s = sin(dr*M_PI/180);
        double c = cos(dr*M_PI/180);
        double nx = c*dx - s*dy;
        double ny = s*dx + c*dy;
        cout << fixed << setprecision(10) << dist(nx, ny, pre[N-1].x, pre[N-1].y) << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}