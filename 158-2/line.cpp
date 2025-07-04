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

int T, N, X;
int arr[51];

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> X;
        arr[0] = 0;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        int ans = 1;
        for (int i = 1; i <= N; i++) {
            ans = max(ans, arr[i]-arr[i-1]);
        }
        ans = max(ans, 2*(X-arr[N]));
        cout << ans << endl;
    }
}