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
ll S;
ll a[100005];
set<ll> s;

int main () {
    cin >> T;
    while (T--) {
        cin >> N >> S;
        ll sum = 0;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
            sum += a[i];
        }
        a[0] = 0;
        if (sum <= S) {
            cout << 0 << endl;
            continue;
        }
        ll idx = 0;
        ll cur = 0;
        bool flag = false;
        ll ans = 0;
        for (int i = 1; i <= N; i++) {
            cur += a[i];
            ll res = cur - a[idx];
            if (res <= S) {
                ans = idx;
            }
            if (a[i] > a[idx]) {
                idx = i;
            }
        }
        cout << ans << endl;
    }
}