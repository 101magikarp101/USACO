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

int N;
double arr[100000];
double total = 0;

bool check (double val) {
    double maxSingle = DBL_MIN;
    double _max = DBL_MIN;
    double _min = DBL_MAX;
    double sum = 0;
    for (int i = 1; i <= N - 2; i++) {
        sum += arr[i] - val;
        _min = min(_min, sum);
        _max = max(_max, sum - _min);
        maxSingle = max(maxSingle, arr[i] - val);
        //cout << "i: " << i << " _max: " << _max << " _min: " << _min << " sum: " << sum << endl;
    }
    //cout << "val: " << val << " _max: " << _max << " maxSingle: " << maxSingle << endl;
    //check if _max is 0
    if (_max == 0) {
        _max = maxSingle;
    }
    //cout << ((total - _max) / N <= val) << endl;
    if ((total - _max) / N <= val) {
        return true;
    } else {
        return false;
    }
}

int main() {
    freopen("sabotage.in", "r", stdin);
    freopen("sabotage.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    double val = 100000;
    for (double dif = 100000; dif > 0.00001; dif /= 2) {
        if (check(val - dif)) {
            val -= dif;
        }
    }
    //print to 3 decimal places
    cout << fixed << setprecision(3) << val << endl;
}