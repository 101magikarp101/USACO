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

int T, N;
ll a[104];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < 2*N; i++) {
            cin >> a[i];
        }
        sort(a, a + 2*N);
        ll ans = 0;
        for (int i = 0; i < 2*N; i+=2) {
            ans += a[i];
        }
        cout << ans << endl;
    }
    return 0;
}