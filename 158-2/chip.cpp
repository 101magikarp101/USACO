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

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        arr[N] = 0;
        ll ans = 0;
        ll cur = 0;
        for (int i = 1; i <= N; i++) {
            if (arr[i] < arr[i-1]) {
                ans += arr[i-1]-arr[i];
            }
        }
        cout << ans-1 << endl;
    }
}