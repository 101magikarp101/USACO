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
ll h, w, x1, y01, x2, y2;

int main () {
    cin >> T;
    while (T--) {
        cin >> h >> w >> x1 >> y01 >> x2 >> y2;
        ll t = x2-x1;
        if (t<0) {
            cout << "Draw" << endl;
            continue;
        }
        ll t1 = (t+1)/2, t2 = t/2;
        ll l1 = max(1LL, y01-t1), r1 = min(w, y01+t1);
        ll l2 = max(1LL, y2-t2), r2 = min(w, y2+t2);
        // cout << "t1: " << t1 << " t2: " << t2 << endl;
        // cout << "l1: " << l1 << " r1: " << r1 << " l2: " << l2 << " r2: " << r2 << endl;
        if (t%2==1) {
            ll l = max(l1, l2), r = min(r1, r2);
            // cout << "l: " << l << " r: " << r << endl;
            if (l <= l2 && r2 <= r) cout << "Alice" << endl;
            else cout << "Draw" << endl;
        } else {
            ll l = max(l1, l2), r = min(r1, r2);
            if (l <= l1 && r1 <= r) cout << "Bob" << endl;
            else cout << "Draw" << endl;
        }
    }
}
