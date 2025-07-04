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

int T, N;
ll dp[1002][1002][2];
ll t[1002][1002][2];
vt<ll> p, n;

int main() {
    cin >> N;
    int po = 0, ne = 0;
    for (int i = 1; i <= N; i++) {
        ll x; cin >> x;
        if (x > 0) {
            p.push_back(x);
            po++;
        } else {
            n.push_back(x);
            ne++;
        }
    }
    sort(p.begin(), p.end());
    sort(n.begin(), n.end(), greater<ll>());
    for (int i = 0; i <= po; i++) {
        for (int j = 0; j <= ne; j++) {
            dp[i][j][0] = 1e18;
            dp[i][j][1] = 1e18;
        }
    }
    t[0][0][0] = 0;
    t[0][0][1] = 0;
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    for (int i = 0; i <= po; i++) {
        for (int j = 0; j <= ne; j++) {
            if (i > 0) {
                t[i][j][0] = min(t[i][j][0], t[i-1][j][0]+abs(p[i-1]-p[i-2]));
                t[i][j][0] = min(t[i][j][0], t[i-1][j][1]+abs(p[i-1]-n[j-1]));
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0]+t[i][j][0]*p[i-1]);
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][1]+t[i][j][0]*p[i-1]);
            }
            if (j > 0) {
                t[i][j][1] = min(t[i][j][1], t[i][j-1][1]+abs(n[j-1]-n[j-2]));
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1]+t[i][j][1]*n[j-1]);
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][0]+t[i][j][1]*n[j-1]);
            }
        }
    }
    cout << "dp: " << endl;
    for (int i = 0; i <= po; i++) {
        for (int j = 0; j <= ne; j++) {
            cout << dp[i][j][0] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i <= po; i++) {
        for (int j = 0; j <= ne; j++) {
            cout << dp[i][j][1] << " ";
        }
        cout << endl;
    }
    cout << min(dp[po][ne][0], dp[po][ne][1]) << endl;
    return 0;
}