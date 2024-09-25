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

int T, N;
int a[200005];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        string s; cin >> s;
        string r = s;
        reverse(r.begin(), r.end());
        if (r<s) {
            if (N%2==1) {
                cout << r << endl;
            } else {
                cout << r<<s<<endl;
            }
        } else {
            if (N%2==1) {
                cout << s<<r<<endl;
            } else {
                cout << s<<endl;
            }
        }
    }
    return 0;
}