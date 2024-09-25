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
#include <unordered_map>
#include <deque>
#include <climits>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T, N, K;

int main () {
    cin >> T;
    for (int t = 0; t<T; t++) {
        cin >> N >> K;
        vt<vt<int>> a(K, vt<int>(N));
        if (K==1) {
            cout << "YES\n";
            continue;
        }
        int prev = 0;
        for (int i = 1; i < N; i++) {
            if (a[1][i] == 1) {
                if (i != 1) {
                    prev = a[1][i-1];
                }
            }
        }
        vt<int> b(N);
        for (int i = 0; i < N; i++) {
            b[i] = i;
        }
    }
}