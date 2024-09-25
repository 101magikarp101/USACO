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

double g(double x) {
    return 3.45*x*(1-x);
}

int main () {
    double x = 0.5;
    for (int i = 0; i < 100000000; i++) {
        x = g(x);
    }
    for (int i = 0; i < 8; i++) {
        cout << fixed << setprecision(15) << x << endl;
        x = g(x);
    }
}