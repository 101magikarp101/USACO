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
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353

using namespace std;

int N, K;
multiset<int> ms;
pii a[200005];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + N, [](pii a, pii b) {
        return a.second < b.second;
    });
    int ans = 0;
    for (int i = 1; i <= K; i++) {
        ms.insert(0);
    }
    for (int i = 0; i < N; i++) {
        auto it = ms.upper_bound(a[i].first);
        if (it != ms.begin()) {
            it--;
            ms.erase(it);
            ms.insert(a[i].second);
            ans++;
        }
    }
    cout << ans << endl;
}