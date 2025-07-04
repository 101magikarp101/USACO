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
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 1000000007

using namespace std;

string alp = "abcdefgh";
string num = "12345678";

int T;

int main() {
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        for (int i = 0; i < 8; i++) {
            if (alp[i] != s[0]) {
                cout << alp[i] << s[1] << endl;
            }
        }
        for (int i = 0; i < 8; i++) {
            if (num[i] != s[1]) {
                cout << s[0] << num[i] << endl;
            }
        }
    }
}