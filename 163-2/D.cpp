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
struct pii {int x, y;};
struct pll {int x, y;};

int T;

int main() {
    cin >> T;
    while (T--) {
        string s; cin >> s;
        int ans = 0;
        for (int l = 1; 2*l <= s.size(); l++) {
            int res = 0;
            for (int i = 0; i < l; i++) {
                if (s[i]=='?'||s[i+l]=='?') {
                    res++;
                } else if (s[i]==s[i+l]) {
                    res++;
                }
            }
            if (res==l) {
                ans = max(ans, l);
            }
            for (int i = l; i < s.size()-l; i++) {
                if (s[i]=='?'||s[i+l]=='?') {
                    res++;
                } else if (s[i]==s[i+l]) {
                    res++;
                }
                if (s[i-l]=='?'||s[i]=='?') {
                    res--;
                } else if (s[i-l]==s[i]) {
                    res--;
                }
                if (res==l) {
                    ans = max(ans, l);
                }
            }
        }
        cout << 2*ans << endl;
    }
    return 0;
}