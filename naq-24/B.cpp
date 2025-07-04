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

int T, N;
int a[200005];

struct point{
    ll x, y;
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
    ll n;
    vt<point> v;
};
ll area(polygon p){
    ll res = 0;
    for (int i = 0; i < p.n; i++){
        res += (p.v[i].x*p.v[(i+1)%p.n].y-p.v[i].y*p.v[(i+1)%p.n].x);
    }
    return abs(res);
}
ll cross(point a, point b, point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int signum(ll x){
    return (x > 0) - (x < 0);
}
bool intersect1(line a, line b) {
    int res1 = signum(cross(a.a, a.b, b.a))*signum(cross(a.a, a.b, b.b));
    int res2 = signum(cross(b.a, b.b, a.a))*signum(cross(b.a, b.b, a.b));
    if (res1 == 0 && res2 == 0) {
        if (a.a > a.b) swap(a.a, a.b);
        if (b.a > b.b) swap(b.a, b.b);
        return a.a <= b.b && b.a <= a.b;
    } else return res1 <= 0 && res2 <= 0;
}
bool intersect(line a, line b) {
    return signum(cross(a.a, a.b, b.a))*signum(cross(a.a, a.b, b.b)) <= 0 && signum(cross(b.a, b.b, a.a))*signum(cross(b.a, b.b, a.b)) <= 0;
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    line l = {{0,0},{0,(ll)1e9}};
    double ans = 1e9;
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        line m = {{x1,y1},{x2,y2}};
        if (intersect(l,m)) {
            double s = (double)(y2-y1)/(x2-x1);
            double d = -s*x1+y1;
            ans = min(ans,d);
        }
    }
    if (ans == 1e9) {
        cout << "-1.0" << endl;
    } else {
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}