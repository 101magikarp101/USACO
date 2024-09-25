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

int T, N, Q;
vt<ll> ls;
unordered_map<ll, ll> m;

ll solve(ll x) {
    if (m.find(x) != m.end()) return m[x];
    int idx = lower_bound(ls.begin(), ls.end(), x)-ls.begin();
    idx--;
    x %= ls[idx];
    if (x == 0) return solve(ls[idx]);
    return solve(x);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N >> Q;
        ls.clear();
        m.clear();
        ll cur = 0;
        for (int i = 0; i < N; i++) {
            ll x, y;
            cin >> x >> y;
            if (x == 1) {
                cur++;
                m[cur] = y;
            } else {
                if (cur > 1e18) continue;
                ll ma = 1e18/cur;
                if (y+1 > ma) {
                    cur = 1e18;
                } else {
                    cur *= (y+1);
                }
            }
            ls.push_back(cur);
        }
        while (Q--) {
            ll x;
            cin >> x;
            ll res = solve(x);
            cout << res << " ";
        }
        cout << '\n';
    }
}