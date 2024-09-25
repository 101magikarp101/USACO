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
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T;
ll a, b;

int main () {
    cin >> T;
    while (T--) {
        cin >> a >> b;
        if ((a+b)%2 == 0) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
}