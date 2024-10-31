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
#define MOD 1000000007

using namespace std;

ll N;

bool check(ll m) {
    ll res = 0;
    for (int i = 1; i <= N; i++) {
        res += min(m/i, N);
    }
    return res >= (N*N+1)/2;
}

int main() {
    cin >> N;
    ll low = 1;
    ll high = N*N;
    ll mid;
    while (low<high) {
        mid = (low+high)/2;
        if (check(mid)) {
            high = mid;
        } else {
            low = mid+1;
        }
    }
    cout << low << endl;
}