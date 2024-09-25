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

struct node {
    ll a, b;
};

int T, N;
ll L;
node a[2005];

bool check (int x) {
    if (x==0) return true;
    ll mi = LLONG_MAX;
    for (int l = x-1; l < N; l++) {
        multiset<int, bool (*)(int, int)> s([](int aa, int b) {
            return a[aa].a > a[b].a;
        });
        ll sum = 0;
        for (int i = 0; i <= l; i++) {
            s.insert(i);
            sum += a[i].a;
        }
        // cout << s.size() << endl;
        while (s.size() > x) {
            sum -= a[*s.begin()].a;
            s.erase(s.begin());
            // cout << "x: " << x << " l: " << l << " sum: " << sum << endl;
        }
        mi = min(mi, sum+a[l].b-a[0].b);
        for (int i = 1; i+l < N; i++) {
            s.insert(i+l);
            sum += a[i+l].a;
            auto it = s.find(i-1);
            if (it != s.end()) {
                sum -= a[i-1].a;
                s.erase(it);
            } else {
                sum -= a[*s.begin()].a;
                s.erase(s.begin());
            }
            mi = min(mi, sum+a[i+l].b-a[i].b);
            // cout << "x: " << x << " i: " << i << " l: " << l << " mi: " << mi << endl;
        }
        // cout << "x: " << x << " l: " << l << " mi: " << mi << endl;
        if (mi <= L) return true;
    }
    return mi <= L;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> L;
        for (int i = 0; i < N; i++) {
            cin >> a[i].a >> a[i].b;
        }
        sort(a, a+N, [](node a, node b) {
            return a.b < b.b;
        });
        int l = 0, r = N;
        while (l < r) {
            int m = (l+r+1)/2;
            if (check(m)) {
                l = m;
            } else {
                r = m-1;
            }                
        }
        cout << l << endl;
    }
    return 0;
}