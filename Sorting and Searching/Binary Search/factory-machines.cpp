#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>

#define ll long long

using namespace std;

ll N, T;
ll arr[200000];

bool check (ll val) {
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += val / arr[i];
        if (sum >= T) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    ll low = 0;
    ll high = 1000000000000000000;
    while (low < high) {
        ll mid = (low + high) / 2;
        if (check(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
}