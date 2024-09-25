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

ll T, N;
ll a[100005];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a + N);
    int l = 1, r = N-2;
    ll ans = -1;
    while (l < r) {
        while (a[r]-a[0]>a[N-1]-a[l]) {
            r--;
        }
        if (r < l-1) break;
        if (a[r]-a[0] == a[N-1]-a[l]) {
            ans = a[r]-a[0];
            break;
        }
        l++;
    }
    cout << ans << endl;
}