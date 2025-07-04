#include <iostream>
#include <vector>

using namespace std;

int main() {
    //read from bcount.in
    freopen("bcount.in", "r", stdin);
    //write to bcount.out
    freopen("bcount.out", "w", stdout);
    
    int N, Q;
    cin >> N >> Q;
    int A[100000];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int H[100000], G[100000], J[100000];
    if (A[0] == 1) {
        H[0] = 1;
    } else if (A[0] == 2) {
        G[0] = 1;
    } else if (A[0] == 3) {
        J[0] = 1;
    }
    for (int i = 1; i < N; i++) {
        if (A[i] == 1) {
            H[i] = H[i - 1] + 1;
            G[i] = G[i - 1];
            J[i] = J[i - 1];
        } else if (A[i] == 2) {
            H[i] = H[i - 1];
            G[i] = G[i - 1] + 1;
            J[i] = J[i - 1];
        } else if (A[i] == 3) {
            H[i] = H[i - 1];
            G[i] = G[i - 1];
            J[i] = J[i - 1] + 1;
        }
    }
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            cout << H[b - 1] << " " << G[b - 1] << " " << J[b - 1] << endl;
        } else {
            cout << H[b - 1] - H[a - 2] << " " << G[b - 1] - G[a - 2] << " " << J[b - 1] - J[a - 2] << endl;
        }
    }
}