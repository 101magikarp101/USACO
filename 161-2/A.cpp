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
int a[200005];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        string a, b, c; cin >> a >> b >> c;
        bool ans = false;
        for (int i = 0; i < N; i++) {
            if (a[i]!=c[i]&&b[i]!=c[i]) {
                ans = true;
                break;
            }
        }
        cout << (ans?"YES":"NO") << endl;
    }
    return 0;
}