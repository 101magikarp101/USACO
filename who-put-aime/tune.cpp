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

int main () {
    double x; cin >> x;
    double hm = pow(2, (double)1/12);
    double ans = log(x/440)/log(hm);
    double res = round(ans);
    cout << fixed << setprecision(12) << ans << " " << res << "\n";
    if (abs(ans-res)<1e-2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}