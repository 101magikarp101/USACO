#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>

using namespace std;

int T;
int N, K, X;

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> K >> X;
        if (X != 1) {
            cout << "YES" << endl;
            cout << N << endl;
            for (int i = 0; i < N; i++) {
                cout << 1 << " ";
            }
            cout << endl;
        } else {
            if (K == 1) {
                cout << "NO" << endl;
            } else if (K == 2) {
                if (N % 2 == 0) {
                    cout << "YES" << endl;
                    cout << N/2 << endl;
                    for (int i = 0; i < N/2; i++) {
                        cout << 2 << " ";
                    }
                    cout << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else if (K >= 3) {
                if (N % 2 == 0) {
                    cout << "YES" << endl;
                    cout << N/2 << endl;
                    for (int i = 0; i < N/2; i++) {
                        cout << 2 << " ";
                    }
                    cout << endl;
                } else {
                    cout << "YES" << endl;
                    cout << N/2 << endl;
                    for (int i = 0; i < N/2 - 1; i++) {
                        cout << 2 << " ";
                    }
                    cout << 3 << " ";
                }
                cout << endl;
            }
        }
    }
}