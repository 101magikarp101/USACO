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
ll a, b;

int main() {
    cin >> T;
    while (T--) {
        cin >> a >> b;
        if (a == 1 || b == 1) {
            cout << 1 << endl;
            cout << a << " " << b << endl;
        } else {
            cout << 2 << endl;
            cout << a-1 << " " << 1 << endl;
            cout << a << " " << b << endl;
        }
    }
}