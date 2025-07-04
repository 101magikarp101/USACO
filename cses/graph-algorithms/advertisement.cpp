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

int N;
ll a[200005];

ll solve(int l) {
    multiset<ll> s;
    for (int i = 0; i < l; i++) {
        s.insert(a[i]);
    }
    ll ans = l*(*s.begin());
    for (int i = l; i < N; i++) {
        s.insert(a[i]);
        s.erase(s.find(a[i-l]));
        ans = max(ans, l*(*s.begin()));
    }
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int l = 1, r = N;
    //ternary search for max
    while (l < r) {
        int m1 = l + (r-l)/3;
        int m2 = r - (r-l)/3;
        if ((r-l)/3 == 0) {
            ll ans = 0;
            for (int i = l; i <= r; i++) {
                ans = max(ans, solve(i));
            }
            cout << ans << endl;
            return 0;
        }
        ll res1 = solve(m1);
        ll res2 = solve(m2);
        if (res1 < res2) {
            l = m1+1;
        } else if (res1 > res2) {
            r = m2-1;
        } else {
            l = m1;
            r = m2;
        }
    }
    cout << solve(l) << endl;
    return 0;
}