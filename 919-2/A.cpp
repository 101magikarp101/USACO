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

int T, N;

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        ll ma = -1;
        ll mi = 1e9+1;
        vt<ll> v;
        for (int i = 0; i < N; i++) {
            ll x, y;
            cin >> x >> y;
            if (x == 1) {
                ma = max(y, ma);
            } else if (x == 2) {
                mi = min(y, mi);
            } else {
                v.push_back(y);
            }
        }
        ll ans = mi-ma+1;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] >= ma && v[i] <= mi) {
                ans--;
            }
        }
        cout << max(0LL, ans) << endl;
    }
}