#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
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

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

struct frac {
    int n, d;
    frac() { n = 0, d = 1; }
    frac(int _n, int _d) {
        n = _n, d = _d;
        this->red();
    }
    frac red() {
        int g = gcd(n, d);
        n/=g, d/=g;
        if (d < 0) n = -n, d = -d;
        return *this;
    }
    frac operator+(const frac &f) const {
        return frac(n*f.d+f.n*d, d*f.d).red();
    }
    frac operator-(const frac &f) const {
        return frac(n*f.d-f.n*d, d*f.d).red();
    }
    frac operator*(const frac &f) const {
        return frac(n*f.n, d*f.d).red();
    }
    frac operator/(const frac &f) const {
        return frac(n*f.d, d*f.n).red();
    }
    bool operator<(const frac &f) const {
        return n*f.d < f.n*d;
    }
    bool operator==(const frac &f) const {
        return n == f.n && d == f.d;
    }
    bool operator!=(const frac &f) const {
        return n != f.n || d != f.d;
    }
    bool operator<=(const frac &f) const {
        return n*f.d <= f.n*d;
    }
    bool operator>=(const frac &f) const {
        return n*f.d >= f.n*d;
    }
    bool operator>(const frac &f) const {
        return n*f.d > f.n*d;
    }
};

struct point{
    int x, y;
    bool operator<(const point &p) const{if(x==p.x)return y<p.y;return x<p.x;}
    bool operator>(const point &p) const{if(x==p.x)return y>p.y;return x>p.x;}
    bool operator==(const point &p) const{return x==p.x&&y==p.y;}
    bool operator!=(const point &p) const{return x!=p.x||y!=p.y;}
    bool operator<=(const point &p) const{if(x==p.x)return y<=p.y;return x<=p.x;}
    bool operator>=(const point &p) const{if(x==p.x)return y>=p.y;return x>=p.x;}
};
struct pointf {
    frac x, y;
    bool operator<(const pointf &p) const{if(x==p.x)return y<p.y;return x<p.x;}
    bool operator>(const pointf &p) const{if(x==p.x)return y>p.y;return x>p.x;}
    bool operator==(const pointf &p) const{return x==p.x&&y==p.y;}
    bool operator!=(const pointf &p) const{return x!=p.x||y!=p.y;}
    bool operator<=(const pointf &p) const{if(x==p.x)return y<=p.y;return x<=p.x;}
    bool operator>=(const pointf &p) const{if(x==p.x)return y>=p.y;return x>=p.x;}
};
struct line{
    point a, b;
};
struct linef{
    pointf a, b;
};
int cross(point a, point b, point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
frac cross(pointf a, pointf b, pointf c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int signum(ll x){
    return (x > 0) - (x < 0);
}
bool intersect(line a, line b) {
    int res1 = signum(cross(a.a, a.b, b.a))*signum(cross(a.a, a.b, b.b));
    int res2 = signum(cross(b.a, b.b, a.a))*signum(cross(b.a, b.b, a.b));
    if (res1 == 0 && res2 == 0) {
        if (a.a > a.b) swap(a.a, a.b);
        if (b.a > b.b) swap(b.a, b.b);
        return a.a <= b.b && b.a <= a.b;
    } else return res1 <= 0 && res2 <= 0;
}
bool intersect(linef a, linef b) {
    frac res1 = cross(a.a, a.b, b.a)*cross(a.a, a.b, b.b);
    frac res2 = cross(b.a, b.b, a.a)*cross(b.a, b.b, a.b);
    if (res1 == frac(0,1) && res2 == frac(0,1)) {
        if (a.a > a.b) swap(a.a, a.b);
        if (b.a > b.b) swap(b.a, b.b);
        return a.a <= b.b && b.a <= a.b;
    } else return res1 <= frac(0,1) && res2 <= frac(0,1);
}
pointf findinter(line a, line b) {
    //find intersection of 2 vectors
    int x1 = a.a.x, y1 = a.a.y, x2 = a.b.x, y2 = a.b.y;
    int x3 = b.a.x, y3 = b.a.y, x4 = b.b.x, y4 = b.b.y;
    int A1 = y2-y1, B1 = x1-x2, C1 = A1*x1+B1*y1;
    int A2 = y4-y3, B2 = x3-x4, C2 = A2*x3+B2*y3;
    int det = A1*B2-A2*B1;
    return {{B2*C1-B1*C2, det}, {A1*C2-A2*C1, det}};
}
pointf findinter(linef a, linef b) {
    //find intersection of 2 vectors
    frac x1 = a.a.x, y1 = a.a.y, x2 = a.b.x, y2 = a.b.y;
    frac x3 = b.a.x, y3 = b.a.y, x4 = b.b.x, y4 = b.b.y;
    frac A1 = y2-y1, B1 = x1-x2, C1 = A1*x1+B1*y1;
    frac A2 = y4-y3, B2 = x3-x4, C2 = A2*x3+B2*y3;
    frac det = A1*B2-A2*B1;
    return {(B2*C1-B1*C2)/det, (A1*C2-A2*C1)/det};
}
double dist(pointf a, pointf b) {
    double x = (double)a.x.n/a.x.d-(double)b.x.n/b.x.d;
    double y = (double)a.y.n/a.y.d-(double)b.y.n/b.y.d;
    return sqrt(x*x+y*y);
}
double distd(point a, point b) {
    double x = a.x-b.x;
    double y = a.y-b.y;
    return sqrt(x*x+y*y);
}
struct state {
    pointf u; double d;
    bool operator<(const state &s) const { return d > s.d; }
};
bool online(pointf p, line l) {
    return cross({{l.a.x,1}, {l.a.y,1}}, {{l.b.x,1}, {l.b.y,1}}, p) == frac(0,1) && p.x >= frac(min(l.a.x, l.b.x), 1) && p.x <= frac(max(l.a.x, l.b.x), 1) && p.y >= frac(min(l.a.y, l.b.y), 1) && p.y <= frac(max(l.a.y, l.b.y), 1);
}

int N;
line a[505];
vt<pointf> adj[505];
map<pointf, double> d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = {{x1, y1}, {x2, y2}};
    }
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (intersect(a[i], a[j])) {
                pointf inter = findinter(a[i], a[j]);
                adj[i].pb(inter);
                adj[j].pb(inter);
            }
        }
    }
    frac sx, sy;
    double sv;
    double sxx, syy;
    cin >> sxx >> syy >> sv;
    sx = {(int)round(sxx*10000), 10000}, sy = {(int)round(syy*10000), 10000};
    pointf start = {sx, sy};
    d[start] = 0;
    priority_queue<state> pq;
    for (int i = 0; i < N; i++) {
        if (online(start, a[i])) {
            adj[i].pb(start);
            for (auto &p : adj[i]) {
                double dis = dist(start, p);
                if (d.find(p) == d.end() || d[p] > dis) {
                    d[p] = dis;
                    pq.push({p, dis});
                }
            }
        }
    }
    while (!pq.empty()) {
        state s = pq.top();
        pq.pop();
        if (s.d > d[s.u]) continue;
        for (int i = 0; i < N; i++) {
            if (online(s.u, a[i])) {
                for (auto &p : adj[i]) {
                    double dis = dist(s.u, p)+s.d;
                    if (d.find(p) == d.end() || d[p] > dis) {
                        d[p] = dis;
                        pq.push({p, dis});
                    }
                }
            }
        }
    }
    double ans = 1e18;
    frac x3, y3, x4, y4;
    double xx3, yy3, xx4, yy4;
    cin >> xx3 >> yy3 >> xx4 >> yy4;
    x3 = {(int)round(xx3*10000), 10000}, y3 = {(int)round(yy3*10000), 10000}, x4 = {(int)round(xx4*10000), 10000}, y4 = {(int)round(yy4*10000), 10000};
    linef lin = {{x3, y3}, {x4, y4}};
    double ev; cin >> ev;
    for (int i = 0; i < N; i++) {
        linef lin2 = {{{a[i].a.x, 1}, {a[i].a.y, 1}}, {{a[i].b.x, 1}, {a[i].b.y, 1}}};
        if (intersect(lin2, lin)) {
            pointf inter = findinter(lin2, lin);
            double t1 = dist({x3, y3}, inter)/ev;
            double t2 = 1e18;
            for (auto &p : adj[i]) {
                double dis = (dist(inter, p)+d[p])/sv;
                ckmin(t2, dis);
            }
            if (t2 < t1) ckmin(ans, t1);
        }
    }
    if (ans == 1e18) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}