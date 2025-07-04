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
#define MOD 1000000007

using namespace std;

int N;
vector<int> a;

int main() {
    cin >> N;
    a = vector<int>(2*N+1);
    a[0] = 0;
    for (int i = 1; i <= 2*N; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp = vector<vector<int>>(N+1, vector<int>());
    vector<vector<int>> final = vector<vector<int>>();
    vector<int> tmp = vector<int>();
    int ma = 0;
    for (int i = 1; i <= 2*N; i++) {
        if (a[i] > ma) {
            if (tmp.size() > 0) {
                final.push_back(tmp);
            }
            tmp = {a[i]};
            ma = a[i];
        } else {
            tmp.push_back(a[i]);
        }
    }
    if (tmp.size() > 0) {
        final.push_back(tmp);
    }
    // cout << "final: " << endl;
    // for (int i = 0; i < final.size(); i++) {
    //     for (int j = 0; j < final[i].size(); j++) {
    //         cout << final[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < dp.size(); i++) {
        dp[i] = vector<int>();
    }
    for (int i = 0; i < final.size(); i++) {
        for (int j = dp.size()-1; j >= 0; j--) {
            if (dp[j].size() > 0 && dp[j].size() + final[i].size() <= N && dp[j+final[i].size()].size() == 0) {
                //merge
                dp[j+final[i].size()].insert(dp[j+final[i].size()].end(), dp[j].begin(), dp[j].end());
                dp[j+final[i].size()].insert(dp[j+final[i].size()].end(), final[i].begin(), final[i].end());
            }
        }
        if (final[i].size() <= N && dp[final[i].size()].size() == 0) {
            dp[final[i].size()].insert(dp[final[i].size()].end(), final[i].begin(), final[i].end());
        }
        // cout << "dp: " << endl;
        // for (int i = 0; i < dp.size(); i++) {
        //     for (int j = 0; j < dp[i].size(); j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if (dp[N].size() > 0) {
            break;
        }
    }
    if (dp[N].size() == 0) {
        cout << "-1" << endl;
        return 0;
    } else {
        vector<bool> vis = vector<bool>(2*N+1);
        vector<int> ans2 = vector<int>();
        for (int i = 0; i < dp[N].size(); i++) {
            vis[dp[N][i]] = true;
        }
        for (int i = 0; i < final.size(); i++) {
            if (!vis[final[i][0]]) {
                ans2.insert(ans2.end(), final[i].begin(), final[i].end());
            }
        }
        for (int i = 0; i < dp[N].size(); i++) {
            cout << dp[N][i] << " ";
        }
        cout << endl;
        for (int i = 0; i < ans2.size(); i++) {
            cout << ans2[i] << " ";
        }
        cout << endl;
    }
}