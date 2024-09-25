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
#include <unordered_map>
#include <deque>
#include <climits>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T, N;
string s;
int c[5] = {1, 0, 0, 0, 1};

int main () {
    cin >> T;
    while (T--) {
        cin >> N >> s;
        string ans = "";
        string cur = "";
        for (int i = 0; i < s.length(); i++) {
            cur += s[i];
            if (c[s[i]-'a'] == 1) {
                if (cur.length() == 2) {
                    ans += '.';
                    ans += cur;
                    cur = "";
                } else {
                    ans += cur[0];
                    ans += '.';
                    ans += cur.substr(1);
                    cur = "";
                }
            }
            if (i == s.length()-1) {
                ans += cur;
            }
        }
        if (ans[0] == '.') {
            ans = ans.substr(1);
        }
        cout << ans << endl;
    }
}