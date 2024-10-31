#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int N, K, B;
    cin >> N >> K >> B;
    int A[100000];
    for (int i = 0; i < N; i++) {
        A[i] = 0;
    }
    for (int i = 0; i < B; i++) {
        int b;
        cin >> b;
        A[b - 1] = 1;
    }
    int sum[100000];
    sum[0] = A[0];
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i - 1] + A[i];
    }
    int min = 100000;
    for (int i = 0; i < N - K; i++) {
        int s = (sum[i + K] - sum[i]);
        if (s < min) {
            min = s;
        }
    }
    if (sum[K-1] < min) {
        min = sum[K-1];
    }
    cout << min << endl;
}