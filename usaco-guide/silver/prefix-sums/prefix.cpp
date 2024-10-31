#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    int A[500000];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int sum[500000];
    sum[0] = A[0];
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i - 1] + A[i];
    }
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            cout << sum[b - 1] << endl;
        } else {
            cout << sum[b - 1] - sum[a - 1] << endl;
        }
    }
}