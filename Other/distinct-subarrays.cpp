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

int N;
ll a[1000005];
ll dp[1000005];
map<ll, ll> m;

int main () {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            dp[i] = 1;
        } else {
            dp[i] = dp[i-1]+1;
            if (m.find(a[i]) != m.end()) {
                dp[i] = min(dp[i], i-m[a[i]]);
            }
        }
        m[a[i]] = i;
        ans += dp[i];
    }
    cout << ans << endl;
}