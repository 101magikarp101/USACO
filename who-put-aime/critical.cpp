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
    ll fx[4];
    for (int i = 3; i >= 0; i--) {
        cin >> fx[i];
    }
    ll fx1[3];
    for (int i = 2; i >= 0; i--) {
        fx1[i] = fx[i+1] * (i+1);
    }
    double m = -fx1[1]/(2*fx1[2]);
    double d = fx1[1]*fx1[1]-4*fx1[2]*fx1[0];
    if (d < 0) {
        cout << "CRITICAL HIT" << endl;
    } else if (d<1e-9) {
        cout << fixed << setprecision(1) << m << endl;
    } else {
        cout << "CRITICAL HIT" << endl;
    
}