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

double ans[16] = {0, 6.0/7, 0, 7.0/8, 6.0/10, 9.0/12, 9.0/14, 9.0/16, 9.0/17, 0, 11.0/17, 9.0/19, 10.0/20, 9.0/21, 9.0/22, 9.0/23};

int main () {
    int x; cin >> x;
    cout << fixed << setprecision(6) << ans[x] << endl;
}