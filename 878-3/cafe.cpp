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

ll T;
ll N, K;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        ll ans;
        if (log2(N+1) < K) {
            ans = N+1;
        } else {
            ans = (ll)pow(2, K);
        }
        cout << ans << endl;
    }
}