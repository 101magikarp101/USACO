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

int x1, y01, x2, y2;
int rad;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double mindisty(double y) {
    double l = -1000000, r = 1000000;
    while (r-l > 1e-7) {
        double m1 = l+(r-l)/3;
        double m2 = r-(r-l)/3;
        double d1 = dist(m1,y,x1,y01)+dist(m1,y,x2,y2);
        double d2 = dist(m2,y,x1,y01)+dist(m2,y,x2,y2);
        if (d1 < d2) {
            r = m2;
        } else {
            l = m1;
        }
    }
    return dist(l,y,x1,y01)+dist(l,y,x2,y2);
}

double mindistx(double x) {
    double l = -1000000, r = 1000000;
    while (r-l > 1e-7) {
        double m1 = l+(r-l)/3;
        double m2 = r-(r-l)/3;
        double d1 = dist(x,m1,x1,y01)+dist(x,m1,x2,y2);
        double d2 = dist(x,m2,x1,y01)+dist(x,m2,x2,y2);
        if (d1 < d2) {
            r = m2;
        } else {
            l = m1;
        }
    }
    return dist(x,l,x1,y01)+dist(x,l,x2,y2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x1 >> y01 >> x2 >> y2 >> rad;
    if ((double)rad-dist(x1,y01,x2,y2) <= 1e-8) {
        int left = min(x1,x2);
        int right = max(x1,x2);
        int up = max(y01,y2);
        int down = min(y01,y2);
        cout << fixed << setprecision(10) << left << " " << down << " " << right << " " << up << endl;
        return 0;
    }
    double mx = (double)(x2+x1)/2;
    double my = (double)(y2+y01)/2;
    double l = my, r = my+1000000;
    while (r-l > 1e-7) {
        double m = (l+r)/2;
        if (mindisty(m) < rad) {
            l = m;
        } else {
            r = m;
        }
    }
    double up = l;
    double down = 2*my-up;
    l = mx, r = mx+1000000;
    while (r-l > 1e-7) {
        double m = (l+r)/2;
        if (mindistx(m) < rad) {
            l = m;
        } else {
            r = m;
        }
    }
    double right = l;
    double left = 2*mx-right;
    cout << fixed << setprecision(10) << left << " " << down << " " << right << " " << up << endl;
    return 0;
}