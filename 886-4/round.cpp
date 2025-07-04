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

int T, N, K;
int a[200001];

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        for (int j = 0; j < N; j++) {
            cin >> a[j];
        }
        sort(a, a+N);
        int largest = 0;
        int cur = 0;
        for (int j = 0; j < N; j++) {
            if (j > 0 && a[j] - a[j-1] > K) {
                if (cur > largest) {
                    largest = cur;
                }
                cur = 1;
            } else {
                cur++;
            }
        }
        if (cur > largest) {
            largest = cur;
        }
        cout << N - largest << endl;
    }
}