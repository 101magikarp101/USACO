#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>

#define ll long long
#define DBL_MAX 1.79769e+308
#define DBL_MIN -1.79769e+308

using namespace std;

ll N, L;
pair<ll, ll> arr[1000000];

bool check (double val) {
    // cout << endl;
    // cout << "val: " << val << endl;
    double right = 0;
    for (int i = 0; i < N; i++) {
        double x = (double) arr[i].first;
        double y = (double) arr[i].second;
        if (abs(y) > val) {
            continue;
        }
        double dist = sqrt(val*val - y*y);
        double l = x - dist;
        double r = x + dist;
        if (l < right) {
            right = max(right, r);
        }
    }
    //cout << "right: " << right << endl;
    if (right < L) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }
    sort(arr, arr + N, [](pair<ll, ll> a, pair<ll, ll> b) {
        if (a.first == b.first) {
            return abs(a.second) < abs(b.second);
        } else {
            return a.first < b.first;
        }
    });
    // cout << "arr: " << endl;
    // for (int i = 0; i < N; i++) {
    //     cout << fixed << setprecision(3) << arr[i].first << " " << arr[i].second << endl;
    // }
    double ans = 0;
    for (double diff = 1e9; diff > 0.00005; diff /= 2) {
        if (check(ans + diff)) {
            ans += diff;
        }
    }
    cout << fixed << setprecision(5) << ans << endl;
}