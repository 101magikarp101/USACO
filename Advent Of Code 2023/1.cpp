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

using namespace std;

string nums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    freopen("1.in", "r", stdin);
    //while there is input
    ll ans = 0;
    string s;
    while (cin >> s) {
        ll l = -1;
        ll r = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                if (l == -1) {
                    l = s[i] - '0';
                }
                r = s[i] - '0';
            } else {
                for (int j = 0; j < 10; j++) {
                    if (s.substr(i, nums[j].length()) == nums[j]) {
                        if (l == -1) {
                            l = j;
                        }
                        r = j;
                    }
                }
            }
        }
        ans += l*10 + r;
    }
    cout << ans << endl;
}