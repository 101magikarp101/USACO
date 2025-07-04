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

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353

using namespace std;

struct dep{
    ll x, y;
};

ll T, N;
dep a[500005];

ll find(multiset<ll> &b, ll x) {
    if (b.empty()) {
        return LLONG_MAX;
    }
    auto it = b.lower_bound(x);
    if (it == b.end()) {
        return x - *prev(it);
    } else if (it == b.begin()) {
        return *it - x;
    } else {
        return min(*it - x, x - *prev(it));
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i].x >> a[i].y;
        }
        sort(a, a+N, [](dep a, dep b) {
            return a.x < b.x;
        });
        multiset<ll> b;
        for (int i = 0; i < N-1; i++) {
            b.insert(a[i].y);
        }
        // cout << "a: ";
        // for (int i = 0; i < N; i++) {
        //     cout << a[i].x << " " << a[i].y << endl;
        // }
        ll res = find(b, a[N-1].x);
        // cout << "res: " << res << endl;
        ll ma = -1;
        for (ll i = N-2; i >= 0; i--) {
            ma = max(ma, a[i+1].y);
            // cout << "b: ";
            // for (auto it = b.begin(); it != b.end(); it++) {
            //     cout << *it << " ";
            // }
            // cout << endl;
            b.extract(a[i].y);
            // cout << "b: ";
            // for (auto it = b.begin(); it != b.end(); it++) {
            //     cout << *it << " ";
            // }
            // cout << endl;
            if (ma < a[i].x) {
                res = min(res, min(find(b, a[i].x), abs(ma-a[i].x)));
            } else {
                res = min(res, ma-a[i].x);
            }
            // cout << "res: " << res << endl;
        }
        cout << res << endl;
    }
}