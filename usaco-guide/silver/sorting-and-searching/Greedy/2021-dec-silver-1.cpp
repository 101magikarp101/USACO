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

struct patch {
    ll x, t;
};

ll K, M, N;
ll a[200005];
patch p[200005];

int main() {
    cin >> K >> M >> N;
    for (int i = 0; i < K; i++) {
        ll x, t;
        cin >> x >> t;
        p[i] = {2*x, t};
    }
    sort(p, p+K, [](patch a, patch b) {
        return a.x < b.x;
    });
    for (int i = 0; i < M; i++) {
        cin >> a[i];
        a[i] *= 2;
    }
    sort(a, a+M);
    vector<ll> ans;
    int idp = K;
    int cur = 0;
    while (idp >= 0) {
        if (idp-1 >= 0 && p[idp-1].x >= a[M-1]) {
            idp--;
            cur += p[idp].t;
        } else {
            break;
        }
    }
    ans.push_back(cur);
    idp = -1;
    cur = 0;
    while (idp < K) {
        if (idp+1 < K && p[idp+1].x <= a[0]) {
            idp++;
            cur += p[idp].t;
        } else {
            break;
        }
    }
    ans.push_back(cur);
    for (int i = 0; i < M-1; i++) {
        cur = 0;
        vector<pll> v;
        while (idp+1 < K && p[idp+1].x > a[i] && p[idp+1].x < a[i+1]) {
            idp++;
            cur += p[idp].t;
            ll d = min(p[idp].x-a[i], a[i+1]-p[idp].x)-1;
            v.push_back({p[idp].x-d, p[idp].t});
            v.push_back({p[idp].x+d+1, -p[idp].t});
        }
        if (v.empty()) continue;
        sort(v.begin(), v.end());
        ll sum = 0;
        ll ma = -1;
        for (int j = 0; j < v.size(); j++) {
            sum += v[j].second;
            ma = max(ma, sum);
        }
        ll res = cur - ma;
        ans.push_back(ma);
        if (res != 0) ans.push_back(res);
    }
    sort(ans.begin(), ans.end(), greater<ll>());
    ll anss = 0;
    for (int i = 0; i < min(N, (ll)ans.size()); i++) {
        anss += ans[i];
    }
    cout << anss << endl;
}