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

using namespace std;

ll N, K;
vector<ll> a;

bool check(ll x) {
    // cout << "x: " << x << endl;
    ll prev = 0;
    for (int i = 0; i < a.size(); i++) {
        if (prev > a[i]) {
            prev = a[i];
        }
        if (a[i]-prev+1 > x) {
            return false;
        }
        prev += x;
        // cout << "i: " << i << " prev: " << prev << endl;
    }
    return prev >= N;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        if (x%K == 0) {
            a.push_back(i);
        }
    }
    // cout << "a: ";
    // for (int i = 0; i < a.size(); i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    ll low = 1;
    ll high = N;
    ll mid;
    while (low < high) {
        mid = (low+high)/2;
        if (check(mid)) {
            high = mid;
        } else {
            low = mid+1;
        }
    }
    cout << low << endl;
}