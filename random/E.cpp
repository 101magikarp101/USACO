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

string e = "271828182845904523536028747135266249775";

int main () {
    string s;
    //readline
    getline(cin, s);
    //remove all spaces
    int ans = 0;
    double d = 0;
    double d1 = 0;
    for (int i = 0; i < s.size(); i++) {
        // cout << (int)s[i] << " ";
        if (i!=s.size()-1) {
            ans += abs((int)s[i+1]-s[i]);
            d += log(abs(s[i+1]-s[i]));
            // cout << abs(s[i+1]-s[i]) << " ";
        }
        d1 += log(s[i]-'a');
        cout << s[i]-'a' << " ";
    }
    cout << endl;
    cout << ans << endl;
    cout << d << endl;
    cout << d1 << endl;
}