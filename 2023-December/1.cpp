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
#include <unordered_set>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

struct cow {
    ll w, a;
    bool operator<(const cow &c) const {
        return w < c.w;
    }
};

ll N, M, K;
cow cows[200005];
set<cow> towers;

int main () {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> cows[i].w >> cows[i].a;
    }
    sort(cows, cows + N, [](cow a, cow b) {
        return a.w > b.w;
    });
    towers.insert({INT_MAX, M});
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll cnt = cows[i].a;
        auto it = towers.lower_bound({cows[i].w+K, 0});
        ll res = 0;
        while (cnt > 0 && it != towers.end()) {
            ll a1 = it->a;
            res = min(cnt, a1);
            cnt -= res;
            a1 -= res;
            ans += res;
            if (a1 == 0) {
                it = towers.erase(it);
            } else {
                towers.erase(it);
                towers.insert({it->w, a1});
                it++;
            }
        }
        towers.insert({cows[i].w, cows[i].a - cnt});
    }
    cout << ans << endl;
}
