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

ll T, N, K;
ll arr[200001];

int main() {
    cin >> T;
    for (ll i = 0; i < T; i++) {
        cin >> N >> K;
        for (ll i = 0; i < N; i++) {
            cin >> arr[i];
        }
        ll index = 0;
        ll target = 1;
        ll x = 0;
        ll y = arr[N-1] - N;
        bool flag = false;
        while (K > 0) {
            K--;
            // cout << "K: " << K << endl;
            for (int i = index; i <= N; i++) {
                index = i;
                if (i == 0) {
                    // cout << "target: " << target << " x: " << x << " i: " << i << endl;
                    if (target < arr[i]) {
                        cout << target << endl;
                        flag = true;
                        break;
                    } else {
                        x = arr[i] - 1;
                    }
                } else if (i == N) {     
                    if (x >= y) {
                        target += N * (K+1);
                        cout << target << endl;
                        flag = true;
                        break;
                    } else {
                    ll temp = target;
                    target = arr[N-1] + target - x;
                    x += temp - x;
                    break;
                    }
                    // cout << "target: " << target << " x: " << x << " i: " << i << endl;
                    break;
                } else if (x+(arr[i] - max(arr[i-1], target) - 1) >= target) {
                    // cout << "target: " << target << " x: " << x << endl;
                    ll temp = target;
                    target = max(arr[i-1], target) + target - x;
                    x = temp;
                    // cout << "target: " << target << " x: " << x << " i: " << i << endl;
                    break;
                } else if (x+(arr[i] - max(arr[i-1], target) - 1) < target) {
                    x += arr[i] - max(arr[i-1], target) - 1;
                    // cout << "target: " << target << " x: " << x << " i: " << i << endl;
                }
            }
            if (flag) {
                break;
            }
        }
        if (!flag) {
            cout << target << endl;
        }
        memset(arr, 0, sizeof(arr));
    }
}