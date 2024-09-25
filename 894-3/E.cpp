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

int T, N, M;
ll D;
ll a[200004];
multiset<ll> s;

int main () {
    cin >> T;
    while (T--) {
        cin >> N >> M >> D;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        ll ans = 0;
        ll sum = 0;
        s.clear();
        for (ll i = 0; i < N; i++) {
            while (!s.empty() && *s.begin() <= 0) {
                sum -= *s.begin();
                s.erase(s.begin());
            }
            if (s.size() == M) {
                sum -= *s.begin();
                s.erase(s.begin());
            }
            s.insert(a[i]);
            sum += a[i];
            ll res = sum - D*(i+1);
            ans = max(ans, res);
        }
        cout << ans << endl;
    }
}