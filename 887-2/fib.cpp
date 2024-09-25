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

#define ll long long

using namespace std;

int T, N, K;

int main() {
    int fib[200001];
    fib[1] = 0;
    fib[2] = 1;
    int limit = 0;
    for (int i = 3; i < 200001; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        if (fib[i] > 200000) {
            limit = i;
            break;
        }
    }
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        if (K >= limit) {
            cout << 0 << endl;
            continue;
        }
        int a = 0;
        int ans = 0;
        // cout << "fib[K-1]: " << fib[K-1] << " fib[K]: " << fib[K] << endl;
        while (N - fib[K-1]*a >= 0 && (N - fib[K-1]*a) / fib[K] >= a) {
            if ((N - fib[K-1]*a) % fib[K] == 0) {
                ans++;
            }
            a++;
        }
        cout << ans << endl;
    }
}