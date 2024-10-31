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
ll a[200001];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int count[20];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 20; j++) {
            if (a[i] & (1 << j)) {
                count[j]++;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll tmp = 0;
        for (int j = 0; j < 20; j++) {
            if (count[j] > 0) {
                tmp += (1 << j);
                count[j]--;
            }
        }
        ans += tmp * tmp;
    }
    cout << ans << endl;
}