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

int N;
ll dp[100005][2];
ll d[100005], l[100005], r[100005];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> r[i];
    }
    ll a, b; cin >> a >> b;
    dp[0][0] = a+b;
    dp[0][1] = a+b;
    return 0;
}