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

ll T, N, M, K;

int main () {
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        if (K == 1) {
            cout << 1 << endl;
        } else if (K == 2) {
            ll ans = 0;
            ans += min(N-1, M);
            M -= N;
            if (M < 0) {
                cout << ans << endl;
                continue;
            }
            ll x = M/N;
            ans += x;
            M -= x*N;
            if (M >= 0) {
                ans++;
            }
            cout << ans << endl;
        } else if (K == 3) {
            ll ans = 0;
            M -= N;
            if (M < 0) {
                cout << ans << endl;
                continue;
            }
            ll x = M/N;
            ans += (N-1)*x;
            M -= x*N;
            ans += min(N-1, M);
            cout << ans << endl;
        } else {
            cout << 0 << endl;
        }
    }
}