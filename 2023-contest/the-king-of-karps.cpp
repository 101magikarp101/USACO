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

int T, M;
ll MOD = 1e9+7;

ll add(ll a, ll b) {
    return (a+b)%MOD;
}

ll mult(ll a, ll b) {
    return (a*b)%MOD;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> M;
        ll ans = 1;
        for (int i = 0; i < M; i++) {
            ll p, e;
            cin >> p >> e;
            ll sum = 1;
            ll temp = 1;
            for (int j = 0; j < e; j++) {
                temp = mult(temp, p);
                temp = mult(temp, p);
                sum = add(sum, temp);
            }
            ans = mult(ans, sum);
        }
        cout << ans << endl;
    }
}