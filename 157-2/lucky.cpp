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
#define pll pair<ll,ll>

using namespace std;

int N;
string s[200005];
map<pll, ll> m;
map<pll, ll> m2;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < N; i++) {
        ll sum = 0;
        for (int j = 0; j < s[i].size(); j++) {
            sum += s[i][j] - '0';
        }
        m2[{s[i].size(),sum}]++;
        for (int j = 0; j <= s[i].size(); j++) {
            ll l = 0;
            for (int k = 0; k < j; k++) {
                l += s[i][k] - '0';
            }
            ll r = 0;
            for (int k = j; k < s[i].size(); k++) {
                r += s[i][k] - '0';
            }
            m[{j-(s[i].size()-j),l-r}]++;
        }
    }
    // for (auto it = m.begin(); it != m.end(); it++) {
    //     cout << it->first.first << " " << it->first.second << " " << it->second << endl;
    // }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= s[i].size(); j++) {
            ll l = 0;
            for (int k = 0; k < j; k++) {
                l += s[i][k] - '0';
            }
            ll r = 0;
            for (int k = j; k < s[i].size(); k++) {
                r += s[i][k] - '0';
            }
            if (j == 0) {
                ans += m[{s[i].size(),r-l}];
            } else if (-(j-(s[i].size()-j)) >= 0) {
                ans += m2[{-(j-(s[i].size()-j)),r-l}];
            }
        }
    }
    cout << ans << endl;
}