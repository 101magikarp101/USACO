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

int N;
int arr[200001];
int dp[200005];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    bool in = false;
    bool has2 = false;
    int temp = 0;
    int l = -1;
    int r = -1;
    for (int i = 0; i < N; i++) {
        if(arr[i] != 0 && !in) {
            in = true;
            l = max(0, i-1);
            temp++;
        }
        if (arr[i] == 2 && in) {
            has2 = true;
        }
        if (arr[i] == 0 && in) {
            r = i;
            if (has2) {
                dp[l] += 1;
                dp[r+1] += -1;
            } else {
                if (dp[l+1] == -1) {
                    dp[l+1] += 1;
                    dp[r+1] += -1;
                } else if (arr[l] == 1) {
                    dp[l] += 1;
                    dp[r+1] += -1;
                } else {
                    dp[l] += 1;
                    dp[r] += -1;
                }
            }
            in = false;
            has2 = false;
        } else if (i == N-1 && in) {
            r = i;
            dp[l] += 1;
            dp[r+1] += -1;
            in = false;
        }
        // cout << "in: " << in << " has2: " << has2 << " l: " << l << " r: " << r << " temp: " << temp << endl;
    }
    int ans = 0;
    // for (int i = 0; i < N; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < N; i++) {
        if (i != 0) {
            dp[i] += dp[i-1];
        }
        if (dp[i] >= 1) {
            ans++;
        }
    }
    cout << N-ans+temp << endl;
}