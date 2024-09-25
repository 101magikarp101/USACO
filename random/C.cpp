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
    double hm = 38071/log2(100);
    double hm2 = 100/pow(0.5, 19035.0/hm)+0.000000001;
    x/=hm2;
    double res = -log2(x)*hm;
    cout << fixed << setprecision(10) << hm << endl;
    cout << fixed << setprecision(10) << hm2 << endl;
    cout << fixed << setprecision(10) << x << endl;
    cout << fixed << setprecision(10) << res << endl;
    ll ans = round(res);
    cout << ans << endl;
}