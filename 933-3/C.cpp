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

int T;

int main() {
    cin >> T;
    while (T--) {
        int N; cin >> N;
        string s; cin >> s;
        int ans = 0;
        for (int i = 0; i < N-2; i++) {
            if (i < N-4 && s.substr(i, 5)=="mapie") {
                ans++;
                i+=4;
            }
            if (s.substr(i, 3)=="map") {
                ans++;
                i+=2;
            }
            if (s.substr(i, 3)=="pie") {
                ans++;
                i+=2;
            }
            // cout << i << " " << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}