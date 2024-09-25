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

bool check (long x) {
    return (x*x*x*x+1)%289 == 0;
}

int main () {
    for (long i = 1; i <= 1000; i++) {
        if (check(i)) {
            cout << i << " " << i%17 << "\n";
        }
    }
}