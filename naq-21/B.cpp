#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
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

struct v3 {
    ld x,y,z;
    v3 operator-(const v3 &a) const { return {x-a.x,y-a.y,z-a.z}; }
    v3 operator+(const v3 &a) const { return {x+a.x,y+a.y,z+a.z}; }
    v3 operator*(const ld &a) const { return {x*a,y*a,z*a}; }
    v3 operator/(const ld &a) const { return {x/a,y/a,z/a}; }
};

struct line {
    v3 s,b;
};

struct asteroid {
    line l;
    ld r;
};

int N;
line a;
asteroid b[35];

ld dist(v3 a, v3 b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

ld dot(v3 a, v3 b) {
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

v3 cross(v3 a, v3 b) {
    return {a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x};
}

ld mag(v3 a) {
    return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}

v3 unit(v3 a) {
    return a/mag(a);
}

ld ptoline(v3 p, line l) {
    // cout << "p: " << p.x << " " << p.y << " " << p.z << endl;
    v3 u = l.b*dot(l.b,l.s-p);
    // cout << "u: " << u.x << " " << u.y << " " << u.z << endl;
    v3 v = (l.s-p)-u;
    v3 w = p+v;
    v3 x = w-l.s;
    // cout << "v: " << v.x << " " << v.y << " " << v.z << endl;
    ld d;
    if (l.b.x != 0) d = x.x/l.b.x;
    else if (l.b.y != 0) d = x.y/l.b.y;
    else d = x.z/l.b.z;
    // cout << "d: " << d << endl;
    if (d < 0) return dist(p,l.s);
    else return mag(v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a.s.x >> a.s.y >> a.s.z >> a.b.x >> a.b.y >> a.b.z;
    a.b = a.b-a.s;
    cin >> N;
    for (int i = 0; i < N; i++) {
        asteroid x;
        cin >> x.l.s.x >> x.l.s.y >> x.l.s.z >> x.l.b.x >> x.l.b.y >> x.l.b.z;
        int M; cin >> M;
        ld r = 0;
        for (int j = 0; j < M; j++) {
            v3 p;
            cin >> p.x >> p.y >> p.z;
            if (dist(p,x.l.s) > r) r = dist(p,x.l.s);
            // cout << "r: " << r << endl;
        }
        x.r = r;
        // cout << "r: " << r << endl;
        b[i] = x;
    }
    bool good = 1;
    for (int i = 0; i < N; i++) {
        v3 u = a.b;
        asteroid x = b[i];
        ld l = 0, r = 1;
        while (r-l > 1e-15) {
            ld m1 = l+(r-l)/3;
            ld m2 = r-(r-l)/3;
            v3 p1 = a.s+u*m1;
            v3 p2 = a.s+u*m2;
            ld d1 = ptoline(p1,x.l);
            ld d2 = ptoline(p2,x.l);
            if (d1 < d2) {
                r = m2;
            } else {
                l = m1;
            }
        }
        v3 p = a.s+u*l;
        ld d = ptoline(p,x.l);
        // cout << "d: " << d << endl;
        if (d < x.r) {
            good = 0;
            break;
        }
    }
    cout << (good?"Go":"Surrender") << endl;
    return 0;
}