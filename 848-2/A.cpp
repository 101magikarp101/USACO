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
int a[100004];

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            sum += a[i];
        }
        int ans = -10000000;
        for (int i = 0; i < N-1; i++) {
            int res = sum - 2*(a[i]+a[i+1]);
            ans = max(ans, res);
        }
        cout << ans << endl;
    }
}