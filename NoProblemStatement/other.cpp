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

int main () {
    int n; cin >> n;
    vt<ll> fib(n+1);
    if (n <= 2) {
        cout << "1.000" << endl;
    } else {
        fib[1] = 1;
        fib[2] = 1;
        for (int i = 3; i <= n; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        cout << fixed << setprecision(3) << (double)1/fib[n] << endl;
    }
}