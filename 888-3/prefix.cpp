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

int T, N;
ll arr[200005];
bool visited[200005];

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        memset(visited, false, sizeof(visited));
        memset(arr, 0, sizeof(arr));
        cin >> N;
        for (int i = 1; i < N; i++) {
            cin >> arr[i];
        }
        int flag = -1;
        bool flag1 = false;
        ll num = -1;
        for (int i = 1; i < N; i++) {
            if (arr[i] - arr[i-1] > N) {
                if (flag != -1) {
                    flag1 = true;
                    break;
                } else {
                    flag = 0;
                    num = arr[i] - arr[i-1];
                }
            } else {
                // cout << "visited[" << arr[i] - arr[i-1] << "]: " << visited[arr[i] - arr[i-1]] << endl;
                if (visited[arr[i] - arr[i-1]]) {
                    if (flag != -1) {
                        flag1 = true;
                        break;
                    }
                    flag = 1;
                    num = arr[i] - arr[i-1];
                } else {
                    visited[arr[i] - arr[i-1]] = true;
                }
            }
            // cout << "flag: " << flag << " num: " << num << " flag1: " << flag1 << endl;
        }
        if (flag1) {
            cout << "NO" << endl;
            continue;
        }
        if (flag == -1) {
            cout << "YES" << endl;
        } else if (flag == 0) {
            ll sum = 0;
            for (int i = 1; i <= N; i++) {
                if (!visited[i]) {
                    sum += i;
                }
            }
            if (sum == num) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (flag == 1) {
            ll sum = 0;
            for (int i = 1; i <= N; i++) {
                if (!visited[i]) {
                    sum += i;
                }
            }
            if (sum == num) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}