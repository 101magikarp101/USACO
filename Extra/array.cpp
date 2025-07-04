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
ll arr[200002];
map<ll, int> m;

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            ll temp;
            cin >> temp;
            arr[i] = temp;
        }
        m.clear();
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            m[arr[i]]++;
            ans += m[arr[i]]-1;
            if (arr[i] == 2) {
                ans += m[1];
            }
            if (arr[i] == 1) {
                ans += m[2];
            }
        }
        cout << ans << endl;
    }
}