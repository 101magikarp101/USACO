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
#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

ll N, Q;
ll arr[150010];
ll sums[150010];
map<ll, ll> m; //index -> value
map<ll, ll> m2; //value -> new index

int main() {
    sums[0] = 0;
    arr[0] = INT_MIN;
    for (int i = 1; i < 150010; i++) {
        arr[i] = INT_MAX;
    }
    cin >> N;
    ll T = 0;
    for (int i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        arr[i] = a;
        m[i] = a;
    }
    sort(arr+1, arr+N+1);
    for (ll i = 1; i <= N; i++) {
        m2[arr[i]] = i;
    }
    for (ll i = 1; i <= N; i++) {
        sums[i] = sums[i-1] + arr[i];
        T += i * arr[i];
    }
    // cout << "arr: ";
    // for (int i = 1; i <= N; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // cout << "sums: ";
    // for (int i = 1; i <= N; i++) {
    //     cout << sums[i] << " ";
    // }
    // cout << endl;
    // cout << "m: ";
    // for (auto it = m.begin(); it != m.end(); it++) {
    //     cout << it->first << " " << it->second << endl;
    // }
    // cout << "m2: ";
    // for (auto it = m2.begin(); it != m2.end(); it++) {
    //     cout << it->first << " " << it->second << endl;
    // }
    // cout << "T: " << T << endl;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        ll a, b;
        cin >> a >> b;
        ll val = m[a];
        ll index = m2[val];
        // cout << "val: " << val << endl;
        // cout << "index: " << index << endl;
        ll ans = 0;
        if (arr[index-1] <= b && b <= arr[index+1]) {
            ans = T - val*index + b*index;
        } else if (b < arr[index-1]) {
            ll rindex = index - 1;
            ll* it = upper_bound(arr+1, arr+N+1, b);
            ll lindex = it - arr;
            // cout << "lindex: " << lindex << endl;
            // cout << "rindex: " << rindex << endl;
            ans = T + (sums[rindex] - sums[lindex-1]) - val*index + b*lindex;
        } else if (b > arr[index+1]) {
            ll lindex = index + 1;
            ll* it = upper_bound(arr+1, arr+N+1, b);
            ll rindex = it - arr - 1;
            // cout << "lindex: " << lindex << endl;
            // cout << "rindex: " << rindex << endl;
            ans = T - (sums[rindex] - sums[lindex-1]) - val*index + b*rindex;
        }
        cout << ans << endl;
    }
}