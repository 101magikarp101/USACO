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

bool isprime(int x) {
    if (x == 1) return false;
    for (int i = 2; i*i <= x; i++) {
        if (x%i == 0) return false;
    }
    return true;
}

int main () {
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 1; i <= x; i++) {
        if (isprime(i)) ans++;
    }
    cout << ans << "\n";
}