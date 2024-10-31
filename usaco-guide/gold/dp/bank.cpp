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

int N, M;
int a[21], b[21];
set<int> s[1005];
vt<set<int>> dp;
vt<int> sum;

int main() {
    cin >> N >> M;
    dp.resize(1<<N);
    sum.resize(1<<N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }
    s[0].insert(0);
    for (int i = 0; i < M; i++) {
        for (int j = 1000; j >= 0; j--) {
            if (j-b[i]>=0 && s[j-b[i]].size()) {
                for (int k : s[j-b[i]]) {
                    s[j].insert(k|(1<<i));
                }
            }
        }
    }
    // cout << "s: " << endl;
    // for (int i = 0; i < 40; i++) {
    //     cout << i << ": ";
    //     for (int j : s[i]) {
    //         cout << bitset<20>(j) << " ";
    //     }
    //     cout << endl;
    // }
    dp[0].insert(0);
    for (int m = 0; m < 1<<N; m++) {
        for (int i = 0; i < N; i++) {
            if (m&(1<<i)) {
                sum[m] += a[i];
            }
        }
        for (int i = 0; i < N; i++) {
            if (m&(1<<i)) {
                int prev = m^(1<<i);
                for (int j : dp[prev]) {
                    for (int k : s[sum[m]]) {
                        if ((k&j)==j) {
                            dp[m].insert(k);
                        }
                    }
                }
            }
        }
    }
    // cout << "dp: " << endl;
    // for (int i = 0; i < 1<<N; i++) {
    //     cout << i << ": ";
    //     for (int j : dp[i]) {
    //         cout << bitset<20>(j) << " ";
    //     }
    //     cout << endl;
    // }
    cout << (dp[(1<<N)-1].size() ? "YES" : "NO") << endl;
    return 0;
}