#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll add(ll a, ll b) {
    return (a+b)%MOD2;
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b%2) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD2-2);
}

ll di(ll a, ll b) {
    return mul(a, inv(b));
}

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

int N, M;
int a[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    DSU d(N);
    bool good = true;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        a[x]++;
        a[y]++;
        if (!d.unite(x, y)) {
            // cout << x << " " << y << endl;
            good = false;
        }
    }
    for (int i = 0; i < N; i++) {
        if (a[i] >= 3) {
            good = false;
            break;
        }
    }
    if (!good) {
        cout << -1 << endl;
        return 0;
    }
    set<ll> s;
    ll hmm = 0;
    ll r = 0;
    for (int i = 0; i < N; i++) {
        if (s.find(d.get(i)) == s.end()) {
            // cout << "i: " << i << " d.get(i): " << d.get(i) << endl;
            r++;
            s.insert(d.get(i));
            if (d.size(i) > 1) hmm++;
        }
    }
    // cout << "r: " << r << " hmm: " << hmm << endl;
    ll fac = 1;
    for (ll i = 2; i <= r; i++) {
        fac = mul(fac, i);
    }
    ll ans = mul(fac, binpow(2, hmm));
    cout << ans << endl;
    return 0;
}