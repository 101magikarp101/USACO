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

int Q;
string s;

int main () {
    cin >> Q;
    while (Q--) {
        cin >> s;
        string cur = "";
        int N = s.length();
        bool ans = false;
        for (int i = N-1; i > 0; i--) {
            string end = s.substr(i, N-i);
            if (i-(N-i) <= 0) break;
            string start = s.substr(i-(N-i), N-i);
            if (start.find(end)!=string::npos && start.size()!=0) {
                ans = true;
                break;
            }
        }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}