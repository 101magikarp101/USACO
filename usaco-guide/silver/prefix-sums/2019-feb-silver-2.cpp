#include <iostream>

using namespace std;

int main () {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int a[1001][1001];
    int sums[1001][1001];
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[y1][x1]++;
        a[y1][x2]--;
        a[y2][x1]--;
        a[y2][x2]++;
    }
    int count = 0;
    sums[0][0] = a[0][0];
    if (sums[0][0] == k) {
        count++;
    }
    for (int i = 1; i < 1000; i++) {
        sums[0][i] = sums[0][i - 1] + a[0][i];
        if (sums[0][i] == k) {
            count++;
        }
        sums[i][0] = sums[i - 1][0] + a[i][0];
        if (sums[i][0] == k) {
            count++;
        }
    }
    for (int i = 1; i < 1000; i++) {
        for (int j = 1; j < 1000; j++) {
            sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + a[i][j];
            if (sums[i][j] == k) {
                count++;
            }
        }
    }
    cout << count << endl;
}