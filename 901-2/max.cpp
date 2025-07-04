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

int T, N;
ll a[5001];

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(a, a+N);
        vector<pair<ll, ll>> v;
        ll h = 0;
        ll idx = 0;
        ll cnt = 1;
        if (N == 1) {
            if (a[0] != 0) {
                cout << 0 << endl;
                continue;
            } else {
                cout << 1 << endl;
                continue;
            }
        }
        if (a[0] == 0) {
            for (int i = 1; i < N; i++) {
                if (a[i] >= a[i-1]+2) {
                    idx = i;
                    h = a[i-1]+1;
                    v.push_back({i-1, cnt});
                    break;
                } else if (i == N-1) {
                    if (a[i] != a[i-1]) {
                        v.push_back({i-1, cnt});
                        cnt = 1;
                    } else {
                        cnt++;
                    }
                    idx = N;
                    v.push_back({i, cnt});
                    h = a[N-1]+1;
                    break;
                }
                if (a[i] != a[i-1]) {
                    v.push_back({i-1, cnt});
                    cnt = 1;
                } else {
                    cnt++;
                }
            }
        } else {
            cout << 0 << endl;
            continue;
        }
        ll dp[5001];
        ll ans = LLONG_MAX;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < idx; i++) {
            if (i==0) {
                dp[i] = a[i]+1;
            } else {
                dp[i] = a[i]+1+dp[i-1];
            }
        }
        for (int i = 0; i < v.size(); i++) {
            ll temp = dp[v[i].first];
            temp -= a[v[i].first]+1;
            temp += (v[i].second-1)*(h-a[v[i].first]-1);
            // cout << "i: " << i << " temp: " << temp << " v[i].first: " << v[i].first << " v[i].second: " << v[i].second << " h: " << h << " a[v[i].first]: " << a[v[i].first] << " dp[v[i].first]: " << dp[v[i].first] << endl;
            ans = min(ans, temp);
        }
        cout << ans << endl;
        memset(a, 0, sizeof(a));
    }
}