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

ll N, K;
ll a[21];

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i < (1 << K); i++) {
        ll tmp = N;
        int cnt = 0;
        for (int j = 0; j < K; j++) {
            if (i & (1 << j)) {
                cnt++;
                tmp /= a[j];
            }
        }
        if (cnt % 2 == 0) {
            ans -= tmp;
        } else {
            ans += tmp;
        }
    }
    cout << ans << endl;
}