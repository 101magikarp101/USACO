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
struct pii {int x, y;};
struct pll {int x, y;};

int T, A, B;
bool a[5000003];
bool b[5000003];

int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    cin >> T >> A >> B;
    a[0] = 1;
    for (int i = 0; i <= T; i++) {
        if (a[i]) {
            if (i+A <= T) a[i+A] = 1;
            if (i+B <= T) a[i+B] = 1;
        }
    }
    for (int i = 0; i <= T; i++) {
        if (a[i]) {
            b[i/2] = 1;
        }
    }
    for (int i = 0; i <= T; i++) {
        if (b[i]) {
            if (i+A <= T) b[i+A] = 1;
            if (i+B <= T) b[i+B] = 1;
        }
    }
    int ans = -1;
    for (int i = T; i >= 0; i--) {
        if (b[i]) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}