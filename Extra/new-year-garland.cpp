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

int T;
ll r, g, b;

int main () {
    cin >> T;
    while (T--) {
        cin >> r >> g >> b;
        ll mx = max(r, max(g, b));
        ll sm = r + g + b;
        if (mx-1 <= sm - mx) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}