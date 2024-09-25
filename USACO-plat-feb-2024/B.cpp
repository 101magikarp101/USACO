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

int N, K;
ll a[302];

int main () {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + N + 1);
    ll ans = 0;
    for (int i = 1; i < N; i++) {
        ans += max(a[i], a[i+1]);
    }
    cout << ans << endl;
}