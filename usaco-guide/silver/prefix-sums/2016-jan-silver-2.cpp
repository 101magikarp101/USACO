#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int N;
    cin >> N;
    int A[50000];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int sum[50000];
    sum[0] = A[0];
    for (int i = 1; i < N; i++) {
        sum[i] = (sum[i - 1] + A[i]) % 7;
    }
    int max = 0;
    for (int i = 1; i < 7; i++) {
        //find the first and last index of sum[i] that is equal to i
        int first = -1;
        int last = -1;
        for (int j = 0; j < N; j++) {
            if (sum[j] == i) {
                first = j;
                break;
            }
        }
        for (int j = N - 1; j >= 0; j--) {
            if (sum[j] == i) {
                last = j;
                break;
            }
        }
        if (first != -1 && last != -1) {
            if (last - first > max) {
                max = last - first;
            }
        }
    }
    int last = -1;
    for (int j = N - 1; j >= 0; j--) {
        if (sum[j] == 0) {
            last = j;
            break;
        }
    }
    if (last != -1) {
        if (last + 1 > max) {
            max = last + 1;
        }
    }
    cout << max << endl;
}