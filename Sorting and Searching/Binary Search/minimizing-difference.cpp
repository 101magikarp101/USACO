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
#define MOD 1000000007

using namespace std;

ll N, K;
map<ll, ll> m;
vector<pll> v;

bool check(ll t) {
    ll l = 0, r = v.size() - 1;
    while (l < r) {
        
    }
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        m[x]++;
    }
    for (auto i : m) {
        v.push_back({i.first, i.second});
    }
    sort(v.begin(), v.end());
    ll low = 0, high = 1e9;
    //min

}