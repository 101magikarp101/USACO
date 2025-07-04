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

int T;
string s, t;

int main () {
    cin >> T;
    while (T--) {
        cin >> s >> t;
        int N = s.length(), M = t.length();
        bool same1 = true, same2 = true;
        for (int i = 1; i < N; i++) {
            if (s[i] != s[i-1]) {
                same1 = false;
                break;
            }
        }
        for (int i = 1; i < M; i++) {
            if (t[i] != t[i-1]) {
                same2 = false;
                break;
            }
        }
        if (same1 && same2) {
            if (s[0] == t[0] && N==M) cout << "YES" << endl;
            else cout << "NO" << endl;
            continue;
        }
        int i = 0, j = 0;
        bool ans = true;
        while (i < N && j < M) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        if (j == M) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}