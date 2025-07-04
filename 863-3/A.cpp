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

int T, N, D;
string s;

int main () {
    cin >> T;
    while (T--) {
        cin >> N >> D >> s;
        bool flag = false;
        for (int i = 0; i < N; i++) {
            if (!flag && D > s[i]-'0') {
                flag = true;
                cout << D;
            }
            cout << s[i];
        }
        if (!flag) cout << D;
        cout << endl;
    }
}