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

set<ll> s;

bool check(ll x) {
    bool ans = true;
    s.clear();
    while (x!=1) {
        //check if x is a happy number
        string str = to_string(x);
        ll sum = 0;
        for (int i = 0; i < str.length(); i++) {
            sum += (str[i]-'0')*(str[i]-'0');
        }
        if (s.find(sum) != s.end()) {
            ans = false;
            break;
        }
        s.insert(sum);
        x = sum;
    }
    return ans;
}

int main () {
    ll x; cin >> x;
    cout << (check(x) ? "YES" : "NO") << "\n";
    // for (int i = 23000000; i <= 23100000; i++) {
    //     if (check(i)) {
    //         cout << i << "\n";
    //     }
    // }
}