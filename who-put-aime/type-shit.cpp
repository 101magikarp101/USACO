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

bool check(int x, int y) {
    return (x/10+y%10)==10&&(x%10-1==y/10);
}

int main () {
    int x, y; cin >> x >> y;
    bool ans = check(x, y)||check(y, x);
    cout << (ans ? "YES" : "NO") << "\n";
}