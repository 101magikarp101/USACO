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

ll MOD = 1e9+7;

ll N, K;
string s;
map<ll, ll> m;

int main() {
    cin >> N >> K >> s;
    ll sum = 0;
    ll min1 = 2147483647;
    ll max1 = -2147483648;
    for (int i = 0; i < N; i++) {
        if (s[i] == '1') {
            sum++;
        } else {
            sum--;
        }
        if (sum < min1) {
            min1 = sum;
        }
        if (sum > max1) {
            max1 = sum;
        }
        m[sum]++;
    }
    ll ans = 0;
    vector<ll> v;
    for (auto i : m) {
        v.push_back(i.second);
        // cout << i.first << " " << i.second << endl;
    }
    if (sum == 0) {
        for (int i = 0; i < v.size(); i++) {
            v[i] *= K;
            v[i] %= MOD;
            ans += v[i]*(v[i]-1)/2;
            ans %= MOD;
        }
        if (m.find(0) != m.end()) {
            ans += v[-min1];
        }
        ans %= MOD;
        cout << ans << endl;
        return 0;
    }
    ll zid = -min1;
    if (sum < 0) {
        sum *= -1;
        zid = v.size()-zid-1;
        reverse(v.begin(), v.end());
        // cout << "sum: " << sum << " zid: " << zid << endl;
    }
    for (int i = 0; i < v.size(); i++) {
        if (i-sum >= 0) {
            v[i] += v[i-sum];
        }
        // cout << "i: " << i << " v[i]: " << v[i] << endl;
    }
    // cout << "v.size()-sum: " << v.size()-sum << endl;
    for (int i = v.size()-1; i >= v.size()-sum; i--) {
        if (i < 0) {
            break;
        }
        ans += (v[i]*(v[i]-1)/2%MOD)*((i/sum+K)%MOD);
        ans %= MOD;
        // cout << "ans: " << ans << endl;
    }
    if (m.find(0) != m.end()) {
        // cout << "zid: " << zid << " v[zid]: " << v[zid] << endl;
        ans += v[zid];
        if (zid - K*sum >= 0) {
            ans -= v[zid-K*sum];
        }
    }
    for (int i = 0; i < v.size(); i++) {
        ll id = v.size()/sum*sum+i%sum;
        if (id >= v.size()) {
            id -= sum;
        }
        ll n = v[id] - v[i];
        ans -= n*(n-1)/2;
        ans %= MOD;
        ans -= n*v[i];
        ans %= MOD;
        ll m = i-sum >= 0 ? v[i-sum] : 0;
        ans -= m*(m-1)/2;
        ans %= MOD;
        ans -= m*(v[id]-m);
        ans %= MOD;
        while (ans < 0) {
            ans += MOD;
        }
        // cout << "i: " << i << " id: " << id << " v[i]: " << v[i] << " v[id]: " << v[id] << " n: " << n << " m: " << m << " ans: " << ans << endl;
    }
    ans %= MOD;
    while (ans < 0) {
        ans += MOD;
    }
    cout << ans << endl;
    return 0;
}