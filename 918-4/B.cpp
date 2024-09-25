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
int a[3][3];

int main () {
    cin >> T;
    while (T--) {
        char ans = 'A';
        for (int i = 0; i < 3; i++) {
            string s;
            cin >> s;
            bool b[3] = {false, false, false};
            for (int j = 0; j < 3; j++) {
                b[s[j]-'A'] = true;
            }
            for (int j = 0; j < 3; j++) {
                if (!b[j]) {
                    ans = j+'A';
                }
            }
        }
        cout << ans << endl;
    }
}