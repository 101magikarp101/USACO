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
    ll w, f;
};

int T;
ll w, f;
int N;
ll s[101];
ll sum = 0;

bool check(ll x) {
    ll W = w*x;
    ll F = f*x;
    if (W > 1000000 || F > 1000000) return true;
    bool dp[1000001];
    memset(dp, false, sizeof(dp));
    if (F < W) swap(F, W);
    dp[0] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = W; j >= 0; j--) {
            if (dp[j] && j+s[i] <= W) {
                dp[j+s[i]] = true;
            }
        }
    }
    int res = 0;
    for (int i = W; i >= 0; i--) {
        if (dp[i]) {
            res = i;
            break;
        }
    }
    return sum-res <= F;
}

int main () {
    cin >> T;
    while (T--) {
        cin >> w >> f;
        cin >> N;
        sum = 0;
        for (int i = 1; i <= N; i++) {
            cin >> s[i];
            sum += s[i];
        }
        ll low = 1, high = 1e6;
        ll mid;
        while (low < high) {
            mid = (low+high)/2;
            if (check(mid)) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        cout << low << endl;
    }
}