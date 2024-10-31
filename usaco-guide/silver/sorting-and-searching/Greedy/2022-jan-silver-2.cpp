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
#define LLONG_MAX 9223372036854775807
#define MOD 998244353

using namespace std;

int N;
ll a[300001];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<int> v;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll sum = 0;
        ll cnt = 0;
        while (!v.empty() && a[v.back()] < a[i]) {
            sum += v.back();
            cnt++;
            v.pop_back();
        }
        if (!v.empty()) {
            sum += v.back();
            cnt++;
        }
        ans += cnt*i - sum + cnt;
        v.push_back(i);
        sum += i;
    }
    cout << ans << endl;
}
