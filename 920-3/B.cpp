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
string s1, s2;

int main () {
    cin >> T;
    while (T--) {
        cin >> N >> s1 >> s2;
        int _01 = 0, _10 = 0;
        for (int i = 0; i < N; i++) {
            if (s1[i] == '0' && s2[i] == '1') _01++;
            else if (s1[i] == '1' && s2[i] == '0') _10++;
        }
        cout << max(_01, _10) << endl;
    }
}