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

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct DSU {
	vector<pll> e;
	DSU(int N) { e = vector<pll>(N, pll(-1, 0)); }

	// get representive component (uses path compression)
	ll get(ll x) { return e[x].first < 0 ? x : e[x].first = get(e[x].first); }

	bool same_set(ll a, ll b) { return get(a) == get(b); }

	ll size(ll x) { return -e[get(x)].first; }

    ll val(ll x) { return e[get(x)].second; }

	bool unite(ll x, ll y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x].first > e[y].first) swap(x, y);
		e[x].first += e[y].first;
        e[x].second += e[y].second;
        e[y].first = x;
		return true;
	}
};

struct bale {
    ll f, s, idx;
};

ll N, M;
ll a[100005];
bale b[100005];

int main () {
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> b[i].f >> b[i].s;
        a[i] = b[i].s;
        b[i].idx = i;
    }
    sort(b, b+N, [](bale a, bale b) {
        return a.s < b.s;
    });
    DSU dsu(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        dsu.e[b[i].idx].second = b[i].f;
    }
    for (int i = 0; i < N; i++) {
        if (b[i].idx > 0 && a[b[i].idx-1] <= a[b[i].idx]) {
            dsu.unite(b[i].idx, b[i].idx-1);
        }
        if (b[i].idx < N-1 && a[b[i].idx+1] <= a[b[i].idx]) {
            dsu.unite(b[i].idx, b[i].idx+1);
        }
        // cout << "idx: " << b[i].idx << " val: " << dsu.val(b[i].idx) << endl;
        if (dsu.val(b[i].idx) >= M) {
            ans = b[i].s;
            break;
        }
    }
    cout << ans << endl;
}