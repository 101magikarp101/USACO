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

ll N, K;
ll arr[200000];

bool check (ll val) {
    ll count = 0;
    ll len = 0;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        len++;
        if (len == 1 && sum > val) {
            return false;
        } else if (sum == val) {
            sum = 0;
            len = 0;
            count++;
        } else if (sum > val) {
            sum = arr[i];
            len = 1;
            count++;
            if (arr[i] == val) {
                sum = 0;
                len = 0;
                count++;
            } else if (arr[i] > val) {
                return false;
            }
        }
    }
    if (sum > 0) {
        count++;
    }
    //cout << "val: " << val << " count: " << count << endl;
    if (count <= K) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    ll low = 1;
    ll high = 2e14;
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