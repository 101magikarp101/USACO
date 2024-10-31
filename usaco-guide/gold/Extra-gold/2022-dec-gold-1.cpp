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

struct cow {
    int p, c, x;
};

struct state {
    int p, c, x;
};

int N, A, B;
cow cows[2005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> A >> B;
    for (int i = 1; i <= N; i++) {
        cin >> cows[i].p >> cows[i].c >> cows[i].x;
    }
    sort(cows+1, cows + N+1, [](cow a, cow b) {
        return a.x < b.x;
    });
    vt<vt<int>> dp(N+1, vt<int>(A+B+1, -1));
    dp[0][A+B] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= A+B; j++) {
            if (dp[i-1][j] != -1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if (j > A) {
                    int hm = (j-A)/cows[i].x;
                    if (hm >= cows[i].c) {
                        if (j-cows[i].x*cows[i].c>=0) dp[i][j-cows[i].x*cows[i].c] = max(dp[i][j-cows[i].x*cows[i].c], dp[i-1][j]+cows[i].p);
                    } else {
                        int c = cows[i].c-hm;
                        if (A-c>=0) {
                            dp[i][A-c] = max(dp[i][A-c], dp[i-1][j]+cows[i].p);
                        }
                    }
                } else if (j<=A && j-cows[i].c>=0) {
                    dp[i][j-cows[i].c] = max(dp[i][j-cows[i].c], dp[i-1][j]+cows[i].p);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= A+B; i++) {
        ans = max(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}