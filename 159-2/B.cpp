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

#define ll long long
#define pll pair<ll, ll>
#define LLONG_MAX 9223372036854775807
#define MOD 1000000007

using namespace std;

int T;
ll N, P, l, t;
ll tasks = 0;

bool check(ll mid) {
    ll res = mid*l + min(tasks, 2*mid)*t;
    // cout << "mid: " << mid << ", res: " << res << endl;
    return res >= P;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> P >> l >> t;
        tasks = (N-1)/7+1;
        ll low = 0;
        ll high = N;
        ll mid;
        //find minimum number of days
        while (low < high) {
            mid = (low+high)/2;
            if (check(mid)) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        cout << N-low << endl;
    }
}