#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];

struct point{
    ll x, y;
    bool operator<(const point &p) const{
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
};

ll cross(point a, point b, point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
        ll res = cross({a, b}, {c, d}, {e, f});
        if (res > 0) cout << "LEFT\n";
        else if (res < 0) cout << "RIGHT\n";
        else cout << "TOUCH\n";
    }
    return 0;
}