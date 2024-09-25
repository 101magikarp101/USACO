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
ll K;
ll a[102];

ll gcd (ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        ll g = abs(a[0] - a[1]);
        for (int i = 2; i < N; i++) {
            g = gcd(g, abs(a[i] - a[i - 1]));
        }
        cout << 2*g << endl;
    }
}