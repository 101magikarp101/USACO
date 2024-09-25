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

ll T, N;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        ll C;
        cin >> N >> C;
        ll squ = 0;
        ll sum = 0;
        for (int j = 0; j < N; j++) {
            ll temp;
            cin >> temp;
            squ += temp * temp;
            sum += temp;
        }
        //cout << "squ: " << squ << " sum: " << sum << endl;
        ll low = 0;
        ll high = lround(sqrt(C/4/N));
        ll ans = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll res = 4*mid*mid*N + 4*mid*sum + squ - C;
            //cout << "res: " << res << " mid: " << mid << endl;
            if (res < 0) {
                low = mid + 1;
            } else if (res == 0) {
                ans = mid;
                break;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << endl;
    }
}