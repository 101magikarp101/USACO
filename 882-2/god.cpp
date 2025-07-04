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

int T, N, K;
int arr[501];
int d[501];

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < N-1; i++) {
            d[i] = abs(arr[i] - arr[i+1]);
        }
        int x = N - K;
        sort(d, d+N-1);
        int ans = 0;
        for (int i = 0; i < x; i++) {
            ans += d[i];
        }
        cout << ans << endl;    
    }
}