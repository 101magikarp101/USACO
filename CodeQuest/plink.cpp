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

struct state {
    ll x;
    string s;
};

int T, N;

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        vt<vt<int>> a(N+1, vt<int>(N+1));
        vt<vt<state>> dp(N+1, vt<state>(N+1));
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> a[i][j];
            }
        }
        dp[0][0] = {a[0][0], ""};
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= i; j++) {
                if (j==0) {
                    dp[i][j] = {dp[i-1][j].x+a[i][j], dp[i-1][j].s+"L"};
                } else if (j==i) {
                    dp[i][j] = {dp[i-1][j-1].x+a[i][j], dp[i-1][j-1].s+"R"};
                } else {
                    if (dp[i-1][j-1].x > dp[i-1][j].x) {
                        dp[i][j] = {dp[i-1][j-1].x+a[i][j], dp[i-1][j-1].s+"R"};
                    } else {
                        dp[i][j] = {dp[i-1][j].x+a[i][j], dp[i-1][j].s+"L"};
                    }
                }
            }
        }
        state ans = {0, ""};
        for (int i = 0; i <= N; i++) {
            if (dp[N][i].x > ans.x) {
                ans = dp[N][i];
            }
        }
        cout << ans.s << " = " << ans.x << endl;
    }
}