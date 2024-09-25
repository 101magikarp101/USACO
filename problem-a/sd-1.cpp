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

int getsigfigs(string s) {
    if (s.find('.') != string::npos) {
        return s.length()-1;
    } else {
        while (s[s.length()-1] == '0') {
            s.pop_back();
        }
        return s.length();
    }
}

int main() {
    string x,y;
    cin >> x >> y;
    int s1 = getsigfigs(x);
    int s2 = getsigfigs(y);
    cout << fixed << setprecision(1) << (double)(s1+s2)/2 << endl;
    return 0;
}
