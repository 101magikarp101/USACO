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

int T;
ll K;
int hm[9] = {0, 1, 2, 3, 5, 6, 7, 8, 9};

string conv(ll x) {
    //convert number to base 9
    string ans = "";
    while (x > 0) {
        ans += to_string(x%9);
        x /= 9;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main () {
    cin >> T;
    while (T--) {
        cin >> K;
        string ans = conv(K);
        for (int i = 0; i < ans.length(); i++) {
            cout << hm[ans[i]-'0'];
        }
        cout << endl;
    }
}