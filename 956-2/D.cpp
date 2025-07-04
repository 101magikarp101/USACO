#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
pii a[200005], b[200005];

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        multiset<int> sa, sb;
        for (int i = 1; i <= N; i++) {
            cin >> a[i].x;
            a[i].y = i;
            sa.insert(a[i].x);
        }
        for (int i = 1; i <= N; i++) {
            cin >> b[i].x;
            b[i].y = i;
            sb.insert(b[i].x);
        }
        if (sa != sb) {
            cout << "NO\n";
            continue;
        }
        sort(a+1, a+N+1, [](pii x, pii y) {
            return x.x < y.x;
        });
        sort(b+1, b+N+1, [](pii x, pii y) {
            return x.x < y.x;
        });
        map<int, int> ma, mb;
        for (int i = 1; i <= N; i++) {
            ma[a[i].x] = i;
            mb[b[i].x] = i;
        }
        for (int i = 1; i <= N; i++) {
            a[i].x = ma[a[i].x];
            b[i].x = mb[b[i].x];
        }
        int ca = 0, cb = 0;
        sort(a+1, a+N+1, [](pii x, pii y) {
            return x.y < y.y;
        });
        sort(b+1, b+N+1, [](pii x, pii y) {
            return x.y < y.y;
        });
        BIT<int> bita(N), bitb(N);
        for (int i = N; i >= 1; i--) {
            int ta = bita.sum(a[i].x-1);
            int tb = bitb.sum(b[i].x-1);
            ca += max(0, a[i].y+ta-a[i].x);
            cb += max(0, b[i].y+tb-b[i].x);
            bita.add(a[i].x, 1);
            bitb.add(b[i].x, 1);
        }
        if (ca%2 == cb%2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}