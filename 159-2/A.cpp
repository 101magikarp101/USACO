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

#define ll long long
#define pll pair<ll, ll>
#define LLONG_MAX 9223372036854775807
#define MOD 1000000007

using namespace std;

int T, N;
string s;
 
int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        cin >> s;
        bool all = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                all = false;
                break;
            }
        }
        cout << (all ? "NO" : "YES") << endl;
    }
}