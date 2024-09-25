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
string s;

int main () {
    cin >> T;
    while (T--) {
        cin >> N;
        cin >> s;
        int p = 0, m = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == '+') {
                p++;
            } else {
                m++;
            }
        }
        cout << max(p, m) - min(p, m) << endl;
    }
}