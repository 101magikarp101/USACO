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

int N, K;
int arr[800][800];
int target;

bool check (int val) {
    // cout << endl;
    // cout << "val: " << val << endl;
    int sums[800][800];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] <= val) {
                sums[i][j] = 1;
            } else {
                sums[i][j] = 0;
            }
            if (i > 0) {
                sums[i][j] += sums[i - 1][j];
            }
            if (j > 0) {
                sums[i][j] += sums[i][j - 1];
            }
            if (i > 0 && j > 0) {
                sums[i][j] -= sums[i - 1][j - 1];
            }
            // cout << "i: " << i << " j: " << j << " sum: " << sums[i][j] << endl;
            if (i >= K - 1 && j >= K - 1) {
                int sum = sums[i][j];
                if (i - K >= 0) {
                    sum -= sums[i - K][j];
                }
                if (j - K >= 0) {
                    sum -= sums[i][j - K];
                }
                if (i - K >= 0 && j - K >= 0) {
                    sum += sums[i - K][j - K];
                }
                // cout << "sum: " << sum << endl;
                if (sum >= target) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    target = (K*K+1) / 2;
    // cout << "target: " << target << endl;
    int low = 0;
    int high = 1000000000;
    while (low < high) {
        int mid = (low + high) / 2;
        if (check(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
}