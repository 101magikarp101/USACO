#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

struct point{
    ll x, y;
    bool operator<(const point &p) const{
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
};

ll cross(point a, point b, point c){
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

int T, N;
point a[200005];
vt<point> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        ll x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    sort(a, a+N);
    for (int i = 0; i < N; i++){
        while (v.size() >= 2 && cross(v[v.size()-2], v.back(), a[i]) < 0){
            v.pop_back();
        }
        v.push_back(a[i]);
    }
    for (int i = N-2, t = v.size(); i >= 0; i--){
        while (v.size() > t && cross(v[v.size()-2], v.back(), a[i]) < 0){
            v.pop_back();
        }
        v.push_back(a[i]);
    }
    v.pop_back();
    cout << v.size() << "\n";
    for (point p : v){
        cout << p.x << " " << p.y << "\n";
    }
    return 0;
}