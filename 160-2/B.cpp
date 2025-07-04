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

int T;
string s;
ll tot[2];
ll cnt[2];

int main() {
    cin >> T;
    while (T--) {
        memset(tot, 0, sizeof(tot));
        memset(cnt, 0, sizeof(cnt));
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            tot[s[i]-'0']++;
        }
        ll ans = s.length();
        for (ll i = 0; i < s.length(); i++) {
            cnt[!(s[i]-'0')]++;
            if (tot[0] - cnt[0] < 0) {
                break;
            }
            if (tot[1] - cnt[1] < 0) {
                break;
            }
            // cout << "i: " << i << " res: " << (ll)s.length()-i-1 << endl;
            ans = min(ans, (ll)s.length()-i-1);
        }
        cout << ans << endl;
    }
}