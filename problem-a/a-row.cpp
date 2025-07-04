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

string r1 = "qwertyuiop";
string r2 = "asdfghjkl";
string r3 = "zxcvbnm";

int main () {
    string s; cin >> s;
    bool ans = false;
    bool res = true;
    for (int i = 0; i < s.length(); i++) {
        if (r1.find(s[i]) == string::npos) {
            res = false;
            break;
        }
    }
    ans |= res;
    res = true;
    for (int i = 0; i < s.length(); i++) {
        if (r2.find(s[i]) == string::npos) {
            res = false;
            break;
        }
    }
    ans |= res;
    res = true;
    for (int i = 0; i < s.length(); i++) {
        if (r3.find(s[i]) == string::npos) {
            res = false;
            break;
        }
    }
    ans |= res;
    cout << (ans ? "YES" : "NO") << "\n";
}