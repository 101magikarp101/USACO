#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>

#define ll long long

using namespace std;

int N, K;
ll low = 0;
ll high = 2000000000;
ll arr[200000];

bool check(ll val) {
    ll count = 0;
    for (int i = N/2; i < N; i++) {
        count += max(0LL, val - arr[i]);
    }
    return count <= K;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    while (low < high) {
        ll mid = (low + high + 1) / 2;
        if (check(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    cout << low << endl;
}