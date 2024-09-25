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

struct point {
    ll x, y;
};

int N, M;
ll dp[1002][1002];
point a[1002], b[1002];
ll d[1002][1002];

int main () {
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    string s1, s2;
    cin >> s1 >> s2;
    a[0] = {x1, y1};
    for (int i = 1; i <= N; i++) {
        if (s1[i-1]=='N') y1++;
        if (s1[i-1]=='S') y1--;
        if (s1[i-1]=='E') x1++;
        if (s1[i-1]=='W') x1--;
        a[i] = {x1, y1};
    }
    b[0] = {x2, y2};
    for (int i = 1; i <= M; i++) {
        if (s2[i-1]=='N') y2++;
        if (s2[i-1]=='S') y2--;
        if (s2[i-1]=='E') x2++;
        if (s2[i-1]=='W') x2--;
        b[i] = {x2, y2};
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            d[i][j] = (a[i].x-b[j].x)*(a[i].x-b[j].x)+(a[i].y-b[j].y)*(a[i].y-b[j].y);
            dp[i][j] = 1e18;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i>0) dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if (j>0) dp[i][j] = min(dp[i][j], dp[i][j-1]);
            if (i>0&&j>0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            if (i>0||j>0) dp[i][j] += d[i][j];
        }
    }
    // cout << "dp:" << endl;
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= M; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[N][M] << endl;
}