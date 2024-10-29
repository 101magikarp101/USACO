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

struct point{
    ll x, y;
    bool operator<(const point &p) const{if(x==p.x)return y<p.y;return x<p.x;}
    bool operator>(const point &p) const{if(x==p.x)return y>p.y;return x>p.x;}
    bool operator==(const point &p) const{return x==p.x&&y==p.y;}
    bool operator!=(const point &p) const{return x!=p.x||y!=p.y;}
    bool operator<=(const point &p) const{if(x==p.x)return y<=p.y;return x<=p.x;}
    bool operator>=(const point &p) const{if(x==p.x)return y>=p.y;return x>=p.x;}
};
struct pointf {
    double x, y;
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
ll cross(point a, point b, point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
double cross(pointf a, pointf b, pointf c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int signum(ll x){
    return (x > 0) - (x < 0);
}
double signum(double x){
    if (abs(x) < 1e-5) return 0;
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
    int res1 = signum(cross(a.a, a.b, b.a))*signum(cross(a.a, a.b, b.b));
    int res2 = signum(cross(b.a, b.b, a.a))*signum(cross(b.a, b.b, a.b));
    if (res1 == 0 && res2 == 0) {
        if (a.a > a.b) swap(a.a, a.b);
        if (b.a > b.b) swap(b.a, b.b);
        return a.a <= b.b && b.a <= a.b;
    } else return res1 <= 0 && res2 <= 0;
}
pointf findinter(line a, line b) {
    //find intersection of 2 vectors
    double x1 = a.a.x, y1 = a.a.y, x2 = a.b.x, y2 = a.b.y;
    double x3 = b.a.x, y3 = b.a.y, x4 = b.b.x, y4 = b.b.y;
    double A1 = y2-y1, B1 = x1-x2, C1 = A1*x1+B1*y1;
    double A2 = y4-y3, B2 = x3-x4, C2 = A2*x3+B2*y3;
    double det = A1*B2-A2*B1;
    return {(B2*C1-B1*C2)/det, (A1*C2-A2*C1)/det};
}
pointf findinter(linef a, linef b) {
    //find intersection of 2 vectors
    double x1 = a.a.x, y1 = a.a.y, x2 = a.b.x, y2 = a.b.y;
    double x3 = b.a.x, y3 = b.a.y, x4 = b.b.x, y4 = b.b.y;
    double A1 = y2-y1, B1 = x1-x2, C1 = A1*x1+B1*y1;
    double A2 = y4-y3, B2 = x3-x4, C2 = A2*x3+B2*y3;
    double det = A1*B2-A2*B1;
    return {(B2*C1-B1*C2)/det, (A1*C2-A2*C1)/det};
}
double dist(pointf a, pointf b) {
    double x = a.x-b.x;
    double y = a.y-b.y;
    return sqrt(x*x+y*y);
}
struct state {
    int u, v; double d; pointf p;
    bool operator<(const state &s) const { return d > s.d; }
};
bool online(pointf p, line l) {
    return signum(cross({(double)l.a.x, (double)l.a.y}, {(double)l.b.x, (double)l.b.y}, p)) == 0 && min(l.a.x, l.b.x) <= p.x && p.x <= max(l.a.x, l.b.x) && min(l.a.y, l.b.y) <= p.y && p.y <= max(l.a.y, l.b.y);
}
struct sus {
    int j; pointf p;
};

int N;
line a[505];
vt<sus> adj[505];
double d[505][505];

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
        for (int j = 0; j < N; j++) {
            d[i][j] = 1e18;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (intersect(a[i], a[j])) {
                pointf inter = findinter(a[i], a[j]);
                adj[i].pb({j, inter});
                adj[j].pb({i, inter});
            }
        }
    }
    auto starttime = chrono::high_resolution_clock::now();
    double sx, sy, sv;
    cin >> sx >> sy >> sv;
    pointf start = {sx, sy};
    priority_queue<state> pq;
    for (int i = 0; i < N; i++) {
        if (online(start, a[i])) {
            for (auto &j : adj[i]) {
                pointf p = j.p;
                double dis = dist(start, p);
                d[i][j.j] = dis;
                pq.push({i, j.j, dis, p});
                // cout << "pushed " << i << " " << j.j << " " << dis << " " << p.x << " " << p.y << endl;
            }
        }
    }
    while (!pq.empty()) {
        state s = pq.top();
        pq.pop();
        if (s.d > d[s.u][s.v]) continue;
        pointf p = s.p;
        for (auto &v : adj[s.v]) {
            pointf p2 = v.p;
            double dis = dist(p, p2);
            if (d[s.v][v.j] > d[s.u][s.v]+dis) {
                d[s.v][v.j] = d[s.u][s.v]+dis;
                pq.push({s.v, v.j, d[s.v][v.j], p2});
            }
        }
    }
    double ans = 1e18;
    double x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    linef lin = {{x3, y3}, {x4, y4}};
    double ev; cin >> ev;
    for (int i = 0; i < N; i++) {
        linef lin2 = {{(double)a[i].a.x, (double)a[i].a.y}, {(double)a[i].b.x, (double)a[i].b.y}};
        if (intersect(lin2, lin)) {
            pointf inter = findinter(lin2, lin);
            double t1 = dist({x3, y3}, inter)/ev;
            double t2 = 1e18;
            for (auto &j : adj[i]) {
                pointf p = j.p;
                double dis = dist(inter, p);
                if (d[i][j.j] == 1e18) continue;
                t2 = min(t2, (d[i][j.j]+dis)/sv);
            }
            if (online(start, a[i])) {
                double dis = dist(start, inter);
                t2 = min(t2, dis/sv);
            }
            if (t2-t1 < 1e-6) ckmin(ans, t1);
        }
    }
    for (int i = 0; i < N; i++) {
        linef lin2 = {{(double)a[i].a.x, (double)a[i].a.y}, {(double)a[i].b.x, (double)a[i].b.y}};
    }
    if (ans == 1e18) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}