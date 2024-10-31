#include <iostream>
#include <climits>

using namespace std;

int main () {
    int n;
    cin >> n;
    long long a[200000];
    long long sums[200000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long min = 0;
    long long max = LLONG_MIN;
    sums[0] = a[0];
    if (sums[0] < min) {
        min = sums[0];
    }
    if (sums[0] > max) {
        max = sums[0];
    }
    for (int i = 1; i < n; i++) {
        sums[i] = sums[i - 1] + a[i];
        if (sums[i] - min > max) {
            max = sums[i] - min;
        }
        if (sums[i] < min) {
            min = sums[i];
        }
    }
    cout << max << endl;
}