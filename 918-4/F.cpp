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

template <class T> class BIT {
public:
    vector<T> bit;
    vector<T> a;
    ll size;

    BIT(ll n) {
        size = n;
        bit.resize(n + 1);
        a.resize(n + 1);
    }

    void add(ll i, T x) {
        a[i] += x;
        for (ll k = i; k <= size; k += k & -k) {
            bit[k] += x;
        }
    }

    void set(ll i, T x) {
        add(i, x - a[i]);
    }

    T sum(ll i) {
        if (i <= 0) return 0;
        if (i > size) i = size;
        T s = 0;
        for (ll k = i; k > 0; k -= k & -k) {
            s += bit[k];
        }
        return s;
    }
};

struct path {
    ll l, r;
};

int T, N;
path a[200003];
pair<ll, ll> b[200003];
map<ll, ll> m;

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        m.clear();
        for (int i = 0; i < N; i++) {
            cin >> a[i].l >> a[i].r;
            b[i] = {a[i].r, i};
        }
        sort(a, a+N, [](path a, path b) {
            return a.l < b.l;
        });
        sort(b, b+N);
        BIT<ll> bit(N+1);
        ll ans = 0;
        for (int i = 1; i <= N; i++) {
            m[b[i-1].first] = i;
        }
        for (int i = N-1; i >= 0; i--) {
            ans += bit.sum(m[a[i].r]);
            bit.set(m[a[i].r], 1);
        }
        cout << ans << endl;
    }
}