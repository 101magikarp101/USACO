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

vt<bool> hextobin(string s) {
    vt<bool> ans;
    for (int i = 0; i < s.size(); i++) {
        int x = s[i]-'0';
        if (x > 9) x -= 7;
        for (int j = 3; j >= 0; j--) {
            ans.push_back((x&(1<<j))>>j);
        }
    }
    return ans;
}

int main () {
    string hex, s;
    cin >> hex >> s;
    vt<bool> bin = hextobin(hex);
    for (int i = 0; i < bin.size(); i++) {
        if (bin[i]) {
            cout << s[i];
        }
    }
    cout << "\n";
}