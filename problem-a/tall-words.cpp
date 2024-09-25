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

string tall = "tidfhjklb";

int main () {
    string s; cin >> s;
    bool good = true;
    for (int i = 0; i < s.length(); i++) {
        if (tall.find(s[i]) == string::npos) {
            good = false;
            break;
        }
    }
    cout << (good ? "YES" : "NO") << "\n";
}