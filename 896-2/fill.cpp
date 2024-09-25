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
#include <chrono>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int T, M, N;

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M;
        if (M == 1) {
            cout << 0 << endl;
            for (int i = 1; i <= N; i++) {
                cout << 0 << endl;
            }
            continue;
        }
        if (N < M) {
            cout << N+1 << endl;
            for (int i = 1; i <= N; i++) {
                for (int j = 0; j < M; j++) {
                    int x = j;
                    x -= i;
                    if (x < 0) {
                        x += M;
                    }
                    cout << x << " ";
                }
                cout << endl;
            }
        } else {
            cout << M << endl;
            for (int i = 1; i <= N; i++) {
                for (int j = 0; j < M; j++) {
                    int x = j;
                    int y = i;
                    if (i >= M) {
                        y = 1;
                    }
                    x -= y;
                    if (x < 0) {
                        x += M;
                    }
                    cout << x << " ";
                }
                cout << endl;
            }
        }
    }
}