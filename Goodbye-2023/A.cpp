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

ll T, N, K;

int main () {
    cin >> T;
    while (T--) {
        cin >> N >> K;
        ll pro = 1;
        for (int i = 0; i < N; i++) {
            ll x;
            cin >> x;
            pro *= x;
        }
        if (2023 % pro == 0) {
            cout << "YES" << endl;
            cout << 2023 / pro << " ";
            for (int i = 1; i < K; i++) {
                cout << 1 << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}