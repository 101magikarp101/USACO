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

int N, Q;
ll K;
ll a[100005];
pll b[100005];

ll get(ll x) {
    if (x <= 0) return 0;
    auto it = lower_bound(b+1, b+N+1, pll(x, 0));
    if (it == b+N+1) {
        return b[N].second + (x-b[N].first+1)*N;
    } else if (it->first == x) {
        return it->second + (it-b);
    } else {
        it = prev(it);
        return it->second + (x-it->first+1)*(it-b);
    }
}

int main() {
    cin >> N >> K >> Q;
    for (int i = 1; i < N; i++) {
        cin >> a[i];
    }
    b[1] = {1, 0};
    for (int i = 2; i <= N; i++) {
        b[i] = {b[i-1].first+a[i-1], b[i-1].second+a[i-1]*(i-1)};
    }
    // cout << "b: ";
    // for (int i = 1; i <= N; i++) {
    //     cout << b[i].first << " " << b[i].second << " | ";
    // }
    // cout << endl;
    for (int q = 1; q <= Q; q++) {
        int M;
        cin >> M;
        vector<int> v;
        for (int i = 0; i < M; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        ll prev = 1;
        ll ans = 0;
        for (int i = 0; i < M; i++) {
            ans += get(v[i]-prev);
            prev = v[i]+1;
        }
        ans += get(K-prev+1);
        cout << ans << endl;
    }
}