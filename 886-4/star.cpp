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

ll T, N;
pair<ll, ll> a[200001];

int main() {
    cin >> T;
    for (ll i = 0; i < T; i++) {
        cin >> N;
        ll temp;
        for (ll j = 0; j < N; j++) {
            ll x, y;
            cin >> x >> y;
            a[j] = make_pair(x, y);
        }
        ll ans = 0;
        sort(a, a+N, [](pair<ll, ll> a, pair<ll, ll> b) {
            return a.first < b.first;
        });
        ll cur = 0;
        for (ll j = 0; j < N; j++) {
            if (j > 0 && a[j].first != a[j-1].first) {
                ans += cur * (cur-1);
                cur = 1;
            } else {
                cur++;
            }
        }
        ans += cur * (cur-1);
        sort(a, a+N, [](pair<ll, ll> a, pair<ll, ll> b) {
            return a.second < b.second;
        });
        cur = 0;
        for (ll j = 0; j < N; j++) {
            if (j > 0 && a[j].second != a[j-1].second) {
                ans += cur * (cur-1);
                cur = 1;
            } else {
                cur++;
            }
        }
        ans += cur * (cur-1);
        sort(a, a+N, [](pair<ll, ll> a, pair<ll, ll> b) {
            return a.first + a.second < b.first + b.second;
        });
        cur = 0;
        for (ll j = 0; j < N; j++) {
            if (j > 0 && a[j].first + a[j].second != a[j-1].first + a[j-1].second) {
                ans += cur * (cur-1);
                cur = 1;
            } else {
                cur++;
            }
        }
        ans += cur * (cur-1);
        sort(a, a+N, [](pair<ll, ll> a, pair<ll, ll> b) {
            return a.first - a.second < b.first - b.second;
        });
        cur = 0;
        for (ll j = 0; j < N; j++) {
            if (j > 0 && a[j].first - a[j].second != a[j-1].first - a[j-1].second) {
                ans += cur * (cur-1);
                cur = 1;
            } else {
                cur++;
            }
        }
        ans += cur * (cur-1);
        cout << ans << endl;
        memset(a, 0, sizeof(a));
    }
}
