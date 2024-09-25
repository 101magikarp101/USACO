#include <iostream>

using namespace std;

int main () {
    int n, q;
    cin >> n >> q;
    int a[1000][1000];
    int sums[1000][1000];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '*') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }
    sums[0][0] = a[0][0];
    for (int i = 1; i < n; i++) {
        sums[0][i] = sums[0][i - 1] + a[0][i];
        sums[i][0] = sums[i - 1][0] + a[i][0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + a[i][j];
        }
    }
    for (int i = 0; i < q; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--;
        x1--;
        y2--;
        x2--;
        int sum = sums[y2][x2];
        if (y1 > 0) {
            sum -= sums[y1 - 1][x2];
        }
        if (x1 > 0) {
            sum -= sums[y2][x1 - 1];
        }
        if (y1 > 0 && x1 > 0) {
            sum += sums[y1 - 1][x1 - 1];
        }
        cout << sum << endl;
    }
}