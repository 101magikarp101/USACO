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
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll res1 = min(min(abs(1-x1), abs(N-x1)), min(abs(1-y1), abs(N-y1)));
        ll res2 = min(min(abs(1-x2), abs(N-x2)), min(abs(1-y2), abs(N-y2)));
        cout << abs(res1-res2) << endl;
    }
}