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
#include <unordered_set>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

ll T, N;
ll a[300005];
pll vals[300005];
DSU dsu(300005);

ll add(ll a, ll b) {
    return (a+b)%MOD;
}

ll sub(ll a, ll b) {
    return (a-b+MOD)%MOD;
}

ll mult(ll a, ll b) {
    return (a*b)%MOD;
}

ll di(ll a, ll b) {
    ll res = a;
    ll e = MOD-2;
    while (e > 0) {
        if (e%2 == 1) {
            res = mult(res, a);
        }
        a = mult(a, a);
        e /= 2;
    }
    return res;
}

ll get(ll x, ll s1, ll s2) {
    if (dsu.same_set(0, x)) {
        return x+1;
    }
    if (dsu.same_set(N-1, x)) {
        return N-x;
    }
    return s1+s2+1;
}

ll get1(ll x) {
    if (dsu.same_set(0, x)) {
        return x+1;
    }
    if (dsu.same_set(N-1, x)) {
        return N-x;
    }
    ll s = dsu.size(x);
    return di(mult(s, s+1), 2)+1;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            vals[i] = {a[i], i};
        }
        sort(vals, vals+N);
        ll ans = 1;
        ll res1 = 1;
        ll res2 = 1;
        for (int i = N-1; i >= 0; i--) {
            ll cur = vals[i].first;
            ll idx = vals[i].second;
            bool f1 = (idx > 0 && a[idx-1] > cur);
            bool f2 = (idx < N-1 && a[idx+1] > cur);
            cout << "idx: " << idx << " f1: " << f1 << " f2: " << f2 << endl;
            if (f1 && f2) {
                res2 = di(res1, get1(idx-1));
                res2 = di(res1, get1(idx+1));
                ll s1 = dsu.size(idx-1);
                ll s2 = dsu.size(idx+1);
                dsu.unite(idx-1, idx);
                dsu.unite(idx, idx+1);
                res2 = mult(res2, get(idx, s1, s2));
                ans = add(ans, res2-1);
                res1 = mult(res1, get1(idx));
            } else if (f1) {
                res2 = di(res1, get1(idx-1));
                ll s1 = dsu.size(idx-1);
                dsu.unite(idx-1, idx);
                res2 = mult(res2, get(idx, s1, 0));
                ans = add(ans, res2-1);
                res1 = mult(res1, get1(idx));
            } else if (f2) {
                res2 = di(res1, get1(idx+1));
                ll s2 = dsu.size(idx+1);
                dsu.unite(idx, idx+1);
                res2 = mult(res2, get(idx, 0, s2));
                ans = add(ans, res2-1);
                res1 = mult(res1, get1(idx));
            } else {
                res2 = di(res1, get1(idx));
                dsu.unite(idx, idx);
                res2 = mult(res2, get(idx, 0, 0));
                ans = add(ans, res2-1);
                res1 = mult(res1, get1(idx));
            }
            cout << "res1: " << res1 << " res2: " << res2 << endl;
            cout << "ans: " << ans << endl;
        }
        cout << ans << endl;
    }
}