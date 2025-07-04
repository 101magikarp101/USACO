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

int T, N;
int a[200001];
// map<int, map<int, int>> m;

int main() {
    // vector<int> primes;
    // primes.push_back(2);
    // for (int i = 2; i <= 200000; i++) {
    //     bool isPrime = true;
    //     for (int j = 0; primes[j] < sqrt(i); j++) {
    //         if (i%primes[j] == 0) {
    //             isPrime = false;
    //             break;
    //         }
    //     }
    //     if (isPrime) {
    //         primes.push_back(i);
    //     }
    // }
    map<int, int> m;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            m[temp]++;
        }
        int ans = 0;
        for (int j = 1; j <= N; j++) {
            int res = 0;
            for (int k = 1; k*k <= j; k++) {
                if (j%k == 0) {
                    res += m[k] + m[j/k];
                    if (k*k == j) {
                        res -= m[k];
                    }
                }
            }
            if (res > ans) {
                ans = res;
            }
        }
        cout << ans << endl;
        m.clear();
    }
}