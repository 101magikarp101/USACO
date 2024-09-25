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

int T;
ll N;

bool check (ll x) {
    ll res = x*(x-1)/2;
    return res <= N;
}

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        ll low = 1, high = 3e9;
        ll mid;
        while (low < high) {
            mid = (low+high+1)/2;
            if (check(mid)) {
                low = mid;
            } else {
                high = mid-1;
            }
        }
        ll res = N - low*(low-1)/2;
        ll ans = low + res;
        cout << ans << endl;
    }
}