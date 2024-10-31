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

string dp[501][501];

string remove(string s) {
    if (s.size() == 1) return s;
    string res = "";
    for (int i = 0; i < s.size(); i++) {
        if (i+1<s.size() && s[i] == s[i+1]) i++;
        else res += s[i];
    }
    return res;
}

int main () {
    string s; cin >> s;
    for (int l = 1; l < s.size(); l++) {
        for (int i = 0; i+l < s.size(); i++) {
            if (l==1) {
                if (s[i] == s[i+l]) dp[i][i+l] = "";
                else dp[i][i+l] = s.substr(i, 2);
            } else {
                int len = INT_MAX;
                string res = "";
                for (int j = i; j < i+l; j++) {
                    string a = dp[i][j], b = dp[j+1][i+l];
                    string c = remove(a+b);
                    if (c.size() < len) {
                        len = c.size();
                        res = c;
                    }
                }
                dp[i][i+l] = res;
            }
        }
    }
    
}