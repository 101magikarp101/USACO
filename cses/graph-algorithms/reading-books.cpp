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
struct pii {int x, y;};
struct pll {int x, y;};

int N;
ll a[200005];

int main() {
    cin >> N;
    ll sum = 0;
    ll ma = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
        ma = max(ma, a[i]);
    }
    cout << (ma*2>sum?ma*2:sum) << endl;
}