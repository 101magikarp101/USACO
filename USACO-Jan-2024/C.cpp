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
ll a[200005];

int check(ll x) {
    ll t = x;
    int last = -1;
    for (int i = 0; i < N; i++) {
        if (t<=a[i]) {
            t+=x-1;
            x--;
            last = i;
        }
        if (x == 0) {
            break;
        }
    }
    if (last == N-1 && x == 0) {
        return 0;
    } else if (last < N-1 && x == 0) {
        return 1;
    } else {
        return -1;
    }
}

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(a, a+N);
        ll ans = min(N*(N+1)/2, a[N-1]);
        ll low = 1, high = N;
        while (low <= high) {
            ll mid = (low+high)/2;
            int res = check(mid);
            // cout << "mid: " << mid << " res: " << res << endl;
            if (res == 0) {
                ans = min(ans, mid*(mid+1)/2);
                high = mid;
                if (low == high) {
                    break;
                }
            } else if (res == 1) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        cout << ans << endl;
    }
}