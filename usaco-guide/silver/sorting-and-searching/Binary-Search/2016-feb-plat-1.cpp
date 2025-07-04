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

struct cow {
    int x, y;
};

struct pai {
    int a, i;
};

int N;
cow a[100005];
cow c[100005];
BIT<int> b1(100005), b2(100005);
map<int, int> cx, cy;

int get(int n) {
    int res1 = b1.sum(n);
    int res2 = b2.sum(n);
    int res3 = b1.sum(N)-res1;
    int res4 = b2.sum(N)-res2;
    return max({res1, res2, res3, res4});
}

int query() {
    int l = 1, r = N;
    //ternary search for min
    while (l < r) {
        if (r-l < 3) {
            int ans = INT_MAX;
            for (int i = l; i <= r; i++) {
                ans = min(ans, get(i));
            }
            return ans;
        }
        int m1 = l + (r-l)/3;
        int m2 = r - (r-l)/3;
        int v1 = get(m1);
        int v2 = get(m2);
        if (v1 < v2) {
            r = m2-1;
        } else if (v1 > v2) {
            l = m1+1;
        } else {
            l = m1;
            r = m2;
        }
    }
    int ans = get(l);
    // cout << "l = " << l << " ans = " << ans << endl;
    return ans;
}

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    cin >> N;
    set<int> xs, ys;
    for (int i = 0; i < N; i++) {
        cin >> a[i].x >> a[i].y;
        xs.insert(a[i].x);
        ys.insert(a[i].y);
    }
    sort(a, a+N, [](cow a, cow b) {
        return a.x < b.x;
    });
    int cnt = 1;
    for (int i : xs) {
        cx[i] = cnt++;
        // cout << "cx[" << i << "] = " << cx[i] << endl;
    }
    cnt = 1;
    for (int i : ys) {
        cy[i] = cnt++;
        // cout << "cy[" << i << "] = " << cy[i] << endl;
    }
    for (int i = 0; i < N; i++) {
        c[i].x = cx[a[i].x];
        c[i].y = cy[a[i].y];
        b2.add(c[i].y, 1);
    }
    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        b1.add(c[i].y, 1);
        b2.add(c[i].y, -1);
        while (i < N-1 && c[i].x == c[i+1].x) {
            i++;
            b1.add(c[i].y, 1);
            b2.add(c[i].y, -1);
        }
        ans = min(ans, query());
    }
    cout << ans << endl;
    return 0;
}