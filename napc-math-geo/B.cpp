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

//AC

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
    int a, b, c;
};

int N, M;
double R;
line a[20];
point c[55];

int signum(int x) {
    return (x > 0) - (x < 0);
}

bool sameside(point p1, point p2, line l) {
    return signum(l.a*p1.x + l.b*p1.y + l.c) == signum(l.a*p2.x + l.b*p2.y + l.c);
}

bool intersect(line l1, line l2) {
    if (l1.b != 0 && l2.b != 0) {
        double m1 = -1.0*l1.a/l1.b, m2 = -1.0*l2.a/l2.b;
        double b1 = -1.0*l1.c/l1.b, b2 = -1.0*l2.c/l2.b;
        if (abs(m1-m2) < 1e-9) return 0;
        double x = (b2-b1)/(m1-m2);
        double y = m1*x+b1;
        return x*x + y*y <= R*R;
    } else if (l1.b == 0 && l2.b == 0) {
        return false;
    } else {
        line l = l1.b == 0 ? l1 : l2;
        line m = l1.b == 0 ? l2 : l1;
        double x = -1.0*l.c/l.a;
        double y = -1.0*m.a/m.b*x - 1.0*m.c/m.b;
        return x*x + y*y <= R*R;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> R;
    for (int i = 0; i < N; i++) {
        cin >> c[i].x >> c[i].y;
    }
    int sec = 1;
    for (int i = 0; i < M; i++) {
        sec++;
        cin >> a[i].a >> a[i].b >> a[i].c;
        for (int j = 0; j < i; j++) {
            if (intersect(a[i], a[j])) {
                sec++;
            }
        }
    }
    bool ans = 1;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            bool good = 0;
            for (int k = 0; k < M; k++) {
                if (!sameside(c[i], c[j], a[k])) {
                    good = 1;
                    break;
                }
            }
            if (!good) {
                ans = 0;
                break;
            }
        }
        if (!ans) break;
    }
    cout << (ans&&sec==N ? "yes" : "no") << endl;
    return 0;
}