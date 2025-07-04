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

struct pai {
    ld q;
    ll d;
    bool operator<(const pai &a) const { return d > a.d; }
};

int N, K;
pll a[1000005];

bool solve(ld x) {
    // cout << "x: " << x << endl;
    priority_queue<pai> pq;
    for (int i = 1; i <= N; i++) {
        pq.push({(ld)a[i].x, a[i].y});
        // cout << "pushing: " << (ld)a[i].x << " " << a[i].y << endl;
        ld ate = 0;
        while (!pq.empty()) {
            pai p = pq.top();
            pq.pop();
            // cout << "p.q: " << p.q << " p.d: " << p.d << endl;
            if (p.d < i) {
                continue;
            }
            ld eat = min(p.q, K*x-ate);
            // cout << "p.q: " << p.q << " p.d: " << p.d << " eat: " << eat << endl;
            // cout << "eat: " << eat << endl;
            p.q -= eat;
            ate += eat;
            if (p.q > 1e-10) {
                // cout << "pushing: " << p.q << " " << p.d << endl;
                pq.push(p);
            }
            if (ate >= K*x) {
                break;
            }
        }
        // cout << fixed << setprecision(10) << ate << endl;
        if (ate < K*x) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> a[i].x >> a[i].y;
    }
    cout << fixed << setprecision(11);
    ld l = 0, r = 1e9;
    while (r-l > 1e-10) {
        ld m = (l+r)/2;
        if (solve(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    if (l < 1e-9) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(10) << l << endl;
    }
    return 0;
}