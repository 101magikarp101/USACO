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
pair<double, double> arr[1000000];

bool check (double val) {
    // cout << endl;
    // cout << "val: " << val << endl;
    double left = DBL_MIN;
    double right = DBL_MAX;
    for (int i = 0; i < N; i++) {
        if (arr[i].second > val) {
            return false;
        }
        double res = sqrt(val * val - arr[i].second * arr[i].second);
        // cout << fixed << setprecision(3) << "arr[i].first: " << arr[i].first << " arr[i].second: " << arr[i].second << endl;
        // cout << fixed << setprecision(3) << "res: " << res << endl;
        if (arr[i].first - res > left) {
            left = arr[i].first - res;
        }
        if (arr[i].first + res < right) {
            right = arr[i].first + res;
        }
        if (left > right) {
            return false;
        }
        //cout << fixed << setprecision(3) << "left: " << left << " right: " << right << endl;
    }
    if (left < right && right >= 0 && left <= L) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }
    sort(arr, arr + N, [](pair<double, double> a, pair<double, double> b) {
        return abs(a.second) < abs(b.second);
    });
    // cout << "arr: " << endl;
    // for (int i = 0; i < N; i++) {
    //     cout << fixed << setprecision(3) << arr[i].first << " " << arr[i].second << endl;
    // }
    double ans = 2e9;
    for (double diff = 1e9; diff > 0.0002; diff /= 2) {
        if (check(ans - diff)) {
            ans -= diff;
        }
    }
    cout << fixed << setprecision(5) << ans << endl;
}