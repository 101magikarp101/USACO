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
int arr[200001];

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int hmm = arr[0];
        for (int i = 1; i < N; i++) {
            hmm &= arr[i];
        }
        if (hmm != 0) {
            cout << 1 << endl;
            continue;
        }
        int ans = 0;
        int temp = 0;
        for (int i = 0; i < N; i++) {
            if (temp == 0) {
                temp = arr[i];
            }
            temp &= arr[i];
            if (temp == 0) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}