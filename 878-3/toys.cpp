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

ll T;
ll N;
ll a[200001];

bool check(ll m) {
    int prev = 0;
    int count = 1;
    for (int i = 0; i < N; i++) {
        if (prev == 0) {
            prev = a[i];
        } else if (a[i] - prev > 2*m) {
            prev = a[i];
            count++;
            if (count > 3) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> a[j];
        }
        sort(a, a+N);
        ll low = 0;
        ll high = 1000000000;
        ll mid;
        while (low < high) {
            mid = (low+high)/2;
            if (check(mid)) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        cout << low << endl;
        memset(a, 0, sizeof(a));
    }
}