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
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int T, N;
ll a[101];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        int neg = 0;
        int pos = 0;
        int zero = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            if (a[i] < 0) neg++;
            else if (a[i] > 0) pos++;
            else zero++;
        }
        if (zero > 0) {
            cout << 0 << endl;
            continue;
        }
        if (neg % 2 == 1) {
            cout << 0 << endl;
            continue;
        } else {
            cout << 1 << endl;
            cout << 1 << " " << 0 << endl;
            continue;
        }
    }
}