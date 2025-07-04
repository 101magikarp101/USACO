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
        ll mi = 1e10;
        ll ma = 0;
        for (int i = 0; i < N; i++) {
            mi = min(mi, arr[i]);
            ma = max(ma, arr[i]);
        }
        ll ans = 0;
        vector<int> v;
        while (ma != mi) {
            if (mi % 2 == 0) {
                mi /= 2;
                ma /= 2;
                ans++;
                v.push_back(0);
            } else {
                mi = (mi+1)/2;
                ma = (ma+1)/2;
                ans++;
                v.push_back(1);
            }
        }
        if (ans > N) {
            cout << ans << endl;
        } else {
            cout << ans << endl;
            for (int i = 0; i < v.size(); i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }
}