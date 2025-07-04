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

struct point{
    double x, y;
    bool operator<(const point &p) const{if(x==p.x)return y<p.y;return x<p.x;}
    bool operator>(const point &p) const{if(x==p.x)return y>p.y;return x>p.x;}
    bool operator==(const point &p) const{return x==p.x&&y==p.y;}
    bool operator!=(const point &p) const{return x!=p.x||y!=p.y;}
    bool operator<=(const point &p) const{if(x==p.x)return y<=p.y;return x<=p.x;}
    bool operator>=(const point &p) const{if(x==p.x)return y>=p.y;return x>=p.x;}
};
struct line{
    point a, b;
};
struct polygon{
    int n;
    vt<point> v;
};
double area(polygon p){
    double res = 0;
    for (int i = 0; i < p.n; i++){
        res += (p.v[i].x*p.v[(i+1)%p.n].y-p.v[i].y*p.v[(i+1)%p.n].x);
    }
    return abs(res)/2;
}
// <a,b> cross <a,c>
double cross(point a, point b, point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int signum(double x){
    return (x > 0) - (x < 0);
}
// intersection of two line segments
bool intersect1(line a, line b) {
    int res1 = signum(cross(a.a, a.b, b.a))*signum(cross(a.a, a.b, b.b));
    int res2 = signum(cross(b.a, b.b, a.a))*signum(cross(b.a, b.b, a.b));
    if (res1 == 0 && res2 == 0) {
        if (a.a > a.b) swap(a.a, a.b);
        if (b.a > b.b) swap(b.a, b.b);
        return a.a <= b.b && b.a <= a.b;
    } else return res1 <= 0 && res2 <= 0;
}
// intersection of two lines
bool intersect(line a, line b) {
    return signum(cross(a.a, a.b, b.a))*signum(cross(a.a, a.b, b.b)) <= 0 && signum(cross(b.a, b.b, a.a))*signum(cross(b.a, b.b, a.b)) <= 0;
}
point intersection(line a, line b) {
    double s1 = cross(a.a, a.b, b.a);
    double s2 = cross(a.a, a.b, b.b);
    return {(b.a.x*s2-b.b.x*s1)/(s2-s1), (b.a.y*s2-b.b.y*s1)/(s2-s1)};
}
int in(point p, polygon po) {
    int cnt = 0;
    for (int i = 0; i < po.n; i++) {
        line side = {po.v[i], po.v[(i+1)%po.n]};
        if (cross(side.a, side.b, p) == 0) {
            if (min(side.a, side.b) <= p && p <= max(side.a, side.b)) return 2;
        }
        int j = (i+1)%po.n;
        if (side.a.y <= p.y && p.y < side.b.y) {
            if (cross(side.a, side.b, p) > 0) cnt++;
        }
        if (side.b.y <= p.y && p.y < side.a.y) {
            if (cross(side.b, side.a, p) > 0) cnt++;
        }
    }
    return cnt%2;
} // 0 = outside, 1 = inside, 2 = on edge
    
double X, Y;
int N;
polygon po;
point a[105];
int ord[105];

// cut polygon with line
void solve(line l) {
    bool right = cross(l.a, l.b, po.v[0]) < 0;
    vt<point> next;
    if (right) next.pb(po.v[0]);
    rep(i,1,po.n) {
        bool cur = cross(l.a, l.b, po.v[i]) < 0;
        if (cur != right) {
            point p = intersection(l, {po.v[i-1], po.v[i]});
            next.pb(p);
        }
        if (cur) next.pb(po.v[i]);
        right = cur;
    }
    bool cur = cross(l.a, l.b, po.v[0]) < 0;
    if (cur != right) {
        point p = intersection(l, {po.v[po.n-1], po.v[0]});
        next.pb(p);
    }
    po.v = next;
    po.n = sz(po.v);
    // cout << "polygon: " << endl;
    // rep(i,0,po.n) cout << po.v[i].x << ' ' << po.v[i].y << endl;
    // cout << "area: " << area(po) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> X >> Y >> N;
    rep(i,0,N) cin >> a[i].x >> a[i].y;
    rep(i,0,N) {
        cin >> ord[i];
        ord[i]--;
    }
    po.n = 4;
    po.v = {{0,0},{X,0},{X,Y},{0,Y}};
    rep(i,0,N) rep(j,i+1,N) {
        solve({a[ord[i]], a[ord[j]]});
    }
    // cout << "polygon: " << endl;
    // rep(i,0,po.n) cout << po.v[i].x << ' ' << po.v[i].y << endl;
    double ans = area(po);
    cout << fixed << setprecision(10) << ans << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}