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
#include <unordered_set>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

ll T, N;
ll arr[1000000];
vector<pll> mi;

int main() {
    cin >> T;
    while (T--) {
        mi.clear();
        cin >> N;
        ll start = -1;
        for (ll i = 0; i < N; i++) {
            cin >> arr[i];
            if (arr[i] == 0) {
                start = i;
            }
        }
        if (N == 1) {
            cout << 1 << endl;
            continue;
        }
        ll a[1000000]; // start with the value of 0;
        for (ll i = 0; i < N; i++) {
            a[i] = arr[(i+start)%N];
        }
        // cout << "a: ";
        // for (int i = 0; i < N; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        ll ans = 0;
        ll res = N;
        for (ll i = 0; i < N; i++) {
            while (!mi.empty() && a[mi.back().first] > a[i]) {
                res -= mi.back().second;
                mi.pop_back();
            }
            if (mi.empty()) {
                res += i*a[i];
                mi.push_back({i, i*a[i]});
            } else {
                res += (i-mi.back().first)*a[i];
                mi.push_back({i, (i-mi.back().first)*a[i]});
            }
            // cout << "i: " << i << " res: " << res << endl;
            ans = max(ans, res);
        }
        cout << ans << endl;
    }
}