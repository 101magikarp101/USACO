#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[100005], b[100005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int max = INT32_MIN;
    for (int i = 0; i < n; i++) {
        int index = upper_bound(b, b + m, a[i]) - b;
        if (index == m) {
            if (a[i] - b[m - 1] > max) {
                max = a[i] - b[m - 1];
            }
        } else if (index == 0) {
            if (b[0] - a[i] > max) {
                max = b[0] - a[i];
            }
        } else {
            int min = INT32_MAX;
            if (b[index] - a[i] < min) {
                min = b[index] - a[i];
            }
            if (a[i] - b[index - 1] < min) {
                min = a[i] - b[index - 1];
            }
            if (min > max) {
                max = min;
            }
        }
    }
    cout << max << endl;
}