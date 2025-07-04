#include <iostream>

using namespace std;

int main () {
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    long long a[401][401];
    long long sums[401][401];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            a[i][j] = 0;
            sums[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int temp;
            cin >> temp;
            a[i][j] = temp;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sums[i][j] = sums[i][j-1] + a[i][j];
        }
    }
    long long max = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            long long sum = 0;
            int t = i;
            while (t >= 1 && i-t <= k) {
                if (j+k-i+t >= 1 && j+k-i+t <= n) {
                    sum += sums[t][j+k-i+t];
                    //cout << "row sum at " << t << " " << j+k-i+t << " is " << sums[t][j+k-i+t] << endl;
                } else {
                    sum += sums[t][n];
                    //cout << "row sum at " << t << " " << n << " is " << sums[t][n] << endl;
                }
                if (j-k+i-t >= 1 && j-k+i-t <= n) {
                    sum -= sums[t][j-k+i-t-1];
                    //cout << "row sum at " << t << " " << j-k+i-t-1 << " is " << sums[t][j-k+i-t-1] << endl;
                }
                t--;
            }
            t = i+1;
            while (t <= n && t-i <= k) {
                if (j+k-t+i >= 1 && j+k-t+i <= n) {
                    sum += sums[t][j+k-t+i];
                    //cout << "row sum at " << t << " " << j+k-t+i << " is " << sums[t][j+k-t+i] << endl;
                } else {
                    sum += sums[t][n];
                    //cout << "row sum at " << t << " " << n << " is " << sums[t][n] << endl;
                }
                if (j-k+t-i >= 1 && j-k+t-i <= n) {
                    sum -= sums[t][j-k+t-i-1];
                    //cout << "row sum at " << t << " " << j-k+t-i-1 << " is " << sums[t][j-k+t-i-1] << endl;
                }
                t++;
            }
            //cout << "sum is " << sum << endl;
            //cout << "sum at " << i << " " << j << " is " << sum << endl;
            if (sum > max) {
                max = sum;
            }
        }
    }
    cout << max << endl;
}