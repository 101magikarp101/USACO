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
int N, M, K, H;
int h[51];

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M >> K >> H;
        for (int i = 0; i < N; i++) {
            cin >> h[i];
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (abs(h[i] - H) % K == 0 && abs(h[i] - H) <= (M-1)*K && H != h[i]) {
                ans++;
            }
        }
        cout << ans << endl;
        memset(h, 0, sizeof(h));
    }
}