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
ll arr[300005];

int main() {
    cin >> N;
    for (ll i = 0; i < N; i++) {
        cin >> arr[i];
    }
    multiset<ll, greater<ll>> ms;
    for (ll i = 0; i < N; i++) {
        ms.insert(arr[i]+i);
    }
    ll ans = *ms.begin();
    for (ll i = 1; i < N; i++) {
        ms.erase(ms.find(arr[i]+i));
        ms.insert(arr[i]);
        ms.erase(ms.find(arr[i-1]));
        ms.insert(arr[i-1]+(N-i));
        ans = min(ans, *ms.begin());
    }
    cout << ans << endl;
}