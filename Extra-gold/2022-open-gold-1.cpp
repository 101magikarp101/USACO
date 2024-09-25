#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>
#include <unordered_map>
#include <deque>
#include <climits>
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

struct point {
    ll x, n;
    bool operator<(const point& p) const {
        return x < p.x;
    }
};

struct state {
    int q;
    ll t, x, n;
};

int N;
multiset<point> s;
vt<state> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    v.resize(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int q; ll t, x, n; cin >> q >> t >> x >> n;
        v[i] = {q, t, x, n};
    }
    sort(v.begin(), v.end(), [](state a, state b) {
        if (a.t-a.x==b.t-b.x) return a.t+a.x > b.t+b.x;
        return a.t-a.x > b.t-b.x;
    });
    for (int i = 0; i < N; i++) {
        int q = v[i].q;
        ll t = v[i].t;
        ll x = v[i].x;
        ll n = v[i].n;
        if (q==1) {
            auto it = s.lower_bound({x+t, 0});
            while (it != s.end()) {
                ll d = min(n, it->n);
                if (it->n-d <= 0) {
                    n-=d;
                    ans+=d;
                    it = s.erase(it);
                    // cout << "d: " << d << " n: " << n << " ans: " << ans << endl;
                } else {
                    ll x = it->x;
                    ll nn = it->n-d;
                    s.erase(it);
                    s.insert({x, nn});
                    n-=d;
                    ans+=d;
                    break;
                }
            }
            // cout << "q: " << q << " t: " << t << " x: " << x << " n: " << n << " ans: " << ans << endl;
            // cout << "s: " << endl;
            // for (auto it = s.begin(); it != s.end(); it++) {
            //     cout << it->x << " " << it->n << endl;
            // }
        } else {
            s.insert({x+t, n});
        }
    }
    cout << ans << endl;
    return 0;
}