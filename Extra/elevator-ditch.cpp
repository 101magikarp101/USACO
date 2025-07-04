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
#define MOD 1000000007

using namespace std;

ll T;
ll t, d, w, m;

int main() {
    freopen("elevator-ditch.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> t >> d >> w >> m;
        if (d==0) {
            cout << 0 << endl;
            continue;
        }
        bool flag = (m % t == 0) && ((m / t - w) % d == 0);
        if (flag) {
            cout << max((ll)0, ((m / t - w) / d)+1) << endl;
        }
        else {
            double T = (double)m / t;
            ll ans = ceil((double)(T - w) / d);
            if (ans < 0) {
                ans = 0;
            }
            cout << ans << endl;
        }
    }
}