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

ll L, N, F, B;
pll a[100005];
bool good[100005];

int main() {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    cin >> L >> N >> F >> B;
    for (int i = 0; i < N; i++) {
        cin >> a[i].first >> a[i].second;
    }
    ll ma = -1;
    for (int i = N-1; i >= 0; i--) {
        if (a[i].second > ma) {
            good[i] = true;
            ma = a[i].second;
        }
    }
    ll ans = 0;
    ll pos = 0;
    ll D = F - B;
    for (int i = 0; i < N; i++) {
        if (good[i]) {
            ans += (a[i].first - pos) * D * a[i].second;
            pos = a[i].first;
        }
    }
    cout << ans << endl;
}