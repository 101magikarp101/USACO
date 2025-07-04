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

int T, N;
pll a[200005];

bool check (int d) {
    ll l = 0;
    ll r = d;
    for (int i = 0; i < N; i++) {
        l = max(l, a[i].first);
        r = min(r, a[i].second);
        if (l > r) return false;
    }
    return true;
}

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i].first >> a[i].second;
        }
    }
    ll low = 0;
    ll high = 1e9;
    //min
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