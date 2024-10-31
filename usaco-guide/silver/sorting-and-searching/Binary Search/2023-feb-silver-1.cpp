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
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 1000000007

using namespace std;

ll T, N, x, y;
ll a[101][3];

bool check(ll m) {
    ll up = 1e10;
    ll down = -1e10;
    for (int i = 0; i < N; i++) {
        ll val = a[i][2] - m*a[i][1];
        // cout << "i: " << i << ", val: " << val << endl;
        if (a[i][0] == 0) {
            if (val < 0) {
                return false;
            }
        } else if (a[i][0] > 0) {
            up = min(up, (ll)floor((double)val/a[i][0]));
        } else {
            down = max(down, (ll)ceil((double)val/a[i][0]));
        }
        // cout << "up: " << up << ", down: " << down << endl;
    }
    // cout << "m: " << m << ", up: " << up << ", down: " << down << endl;
    up = min(up, x);
    down = max(down, 1ll);
    if (up >= down) {
        up = m-up;
        down = m-down;
        swap(up, down);
        up = min(up, y);
        down = max(down, 1ll);
        if (up >= down) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> x >> y;
        for (int i = 0; i < N; i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            a[i][0] -= a[i][1];
        }
        // cout << "a: " << endl;
        // for (int i = 0; i < N; i++) {
        //     cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl;
        // }
        ll low = 0;
        ll high = 2e9;
        ll mid;
        //find max
        while (low < high) {
            mid = (low+high+1)/2;
            if (check(mid)) {
                low = mid;
            } else {
                high = mid-1;
            }
        }
        cout << x+y-low << endl;
    }
}