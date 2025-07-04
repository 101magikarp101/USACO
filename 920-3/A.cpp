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
map<int, vt<int>> m;

int main () {
    cin >> T;
    while (T--) {
        m.clear();
        for (int i = 0; i < 4; i++) {
            int x, y;
            cin >> x >> y;
            m[x].push_back(y);
        }
        int res = m.begin()->second[0]-m.begin()->second[1];
        cout << res*res << endl;
    }
}