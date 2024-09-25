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

int T;
int arr[501];

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;
            arr[i] = a;
        }
        int ans = 2147483647;
        bool flag = false;
        for (int i = 0; i < N-1; i++) {
            if (arr[i+1] < arr[i]) {
                cout << 0 << endl;
                flag = true;
                break;
            }
            if ((arr[i+1] - arr[i]) / 2 + 1< ans) {
                ans = (arr[i+1] - arr[i]) / 2 + 1;
            }
        }
        if (!flag) {
            cout << ans << endl;
        }
        memset(arr, 0, sizeof(arr));
    }
}