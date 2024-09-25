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

int T, N, M, K;
int a[103], b[103];

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> b[i];
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (a[i]+b[j]<=K) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}