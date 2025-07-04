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

using namespace std;

ll T, N;
ll M;
pll arr[100004];
vector<ll> comp;
map<ll, ll> m;

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            ll x, y;
            cin >> x >> y;
            arr[i] = {x, (ll)y+1};
            comp.push_back(x);
            comp.push_back(y);
            comp.push_back((ll)y+1);
        }
        comp.push_back(1);
        comp.push_back(M);
        comp.push_back(M+1);
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());
        for (ll i = 0; i < comp.size(); i++) {
            m[comp[i]] = i;
        }
        // cout << "comp: ";
        // for (int i = 0; i < comp.size(); i++) {
        //     cout << comp[i] << " ";
        // }
        // cout << endl;
        vector<ll> dp(comp.size(), 0);
        for (int i = 0; i < N; i++) {
            dp[m[arr[i].first]]++;
            dp[m[arr[i].second]]--;
        }
        ll max = dp[0];
        ll id = 0;
        for (int i = 1; i < dp.size(); i++) {
            dp[i] += dp[i-1];
            if (dp[i] > max) {
                max = dp[i];
                id = i;
            }
        }
        // cout << "dp before: ";
        // for (int i = 0; i < dp.size(); i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        dp = vector<ll>(comp.size(), 0);
        for (int i = 0; i < N; i++) {
            if (m[arr[i].first] <= id && id < m[arr[i].second]) {
                dp[m[arr[i].first]]++;
                dp[m[arr[i].second]]--;
            }
        }
        max = dp[0];
        ll min = dp[0];
        for (int i = 1; i < dp.size(); i++) {
            dp[i] += dp[i-1];
        }
        if (m.find(M+1) != m.end()) dp.erase(dp.begin()+m[M+1]);
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] > max) {
                max = dp[i];
            }
            if (dp[i] < min) {
                min = dp[i];
            }
        }
        // cout << "dp after: ";
        // for (int i = 0; i < dp.size(); i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        cout << max - min << endl;
        comp.clear();
        m.clear();
    }
}