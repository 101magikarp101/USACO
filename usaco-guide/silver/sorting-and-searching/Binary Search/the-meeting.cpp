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

int N;
pll a[60005];

bool check(double t) {
    double l = -1e9, r = 1e9;
    for (int i = 0; i < N; i++) {
        double l1 = a[i].second - t * a[i].first;
        double r1 = a[i].second + t * a[i].first;
        l = max(l, l1);
        r = min(r, r1);
    }
    return l <= r;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i].second;
    }
    for (int i = 0; i < N; i++) {
        cin >> a[i].first;
    }
    double low = 0, high = 1e9;
    while (high - low > 5e-7) {
        double mid = (low + high) / 2;
        if (check(mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    cout << fixed << setprecision(7) << low << endl;
}