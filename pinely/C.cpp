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
#define INT_MAX 2147483647

using namespace std;

ll T, N;
vector<ll> l;
set<ll> r;
ll c[100005];
ll res[100005];

int main() {
    cin >> T;
    while (T--) {
        l.clear();
        r.clear();
        cin >> N;
        for (int i = 0; i < N; i++) {
            ll x;
            cin >> x;
            l.push_back(x);
        }
        for (int i = 0; i < N; i++) {
            ll x;
            cin >> x;
            r.insert(x);
        }
        for (int i = 0; i < N; i++) {
            cin >> c[i];
        }
        sort(l.begin(), l.end());
        sort(c, c + N);
        for (int i = N-1; i >= 0; i--) {
            auto it = r.upper_bound(l[i]);
            res[i] = *it - l[i];
            r.erase(it);
        }
        sort(res, res + N, greater<ll>());
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            ans += res[i] * c[i];
        }
        cout << ans << endl;
    }
}