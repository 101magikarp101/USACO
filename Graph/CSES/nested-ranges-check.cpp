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

struct seg{
    int l, r, i;
};

int N;
seg a[200005];
map<int,int> m;

int main() {
    cin >> N;
    set<int> s;
    for (int i = 0; i < N; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].i = i;
        s.insert(a[i].l);
    }
    int cnt = 1;
    for (int x : s) {
        m[x] = cnt++;
    }
    for (int i = 0; i < N; i++) {
        a[i].l = m[a[i].l];
    }
    sort(a, a + N, [](seg a, seg b) {
        if (a.r == b.r) return a.l > b.l;
        return a.r < b.r;
    });
    vt<int> ans(N);
    // int ma = -1;
    BIT<int> bit(N+1);
    for (int i = 0; i < N; i++) {
        ans[a[i].i] = bit.sum(N) - bit.sum(a[i].l-1);
        bit.add(a[i].l, 1);
        // cout << "i: " << i << " l: " << a[i].l << " r: " << a[i].r << " ans: " << ans[a[i].i] << endl;
    }
    vt<int> ans2(N);
    // int mi = INT_MAX;
    BIT<int> bit2(N+1);
    for (int i = N - 1; i >= 0; i--) {
        ans2[a[i].i] = bit2.sum(a[i].l);
        bit2.add(a[i].l, 1);
        // cout << "i: " << i << " l: " << a[i].l << " r: " << a[i].r << " ans: " << ans2[a[i].i] << endl;
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << ans2[i] << " ";
    }
    cout << endl;
    return 0;
}