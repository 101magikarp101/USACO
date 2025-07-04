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

int N;
ll f[91];

int main () {
    cin >> N;
    f[1]=0;
    f[2]=1;
    for (int i = 3; i < 91; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cout << x << " = " << f[x] << endl;
    }
}