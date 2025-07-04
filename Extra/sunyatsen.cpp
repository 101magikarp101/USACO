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
#define vi vector<int>
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define LLONG_MAX 9223372036854775807
#define LLONG_MIN -9223372036854775808
#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

string s;
string t = "sysu";
int a[4];

int main() {
    cin >> s;
    ll prev = 0;
    memset(a, -1, sizeof(a));
    ll ans = 0;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 3; j >= 0; j--) {
            if (s[i] == t[j]) {
                if (j == 0) {
                    a[0] = i;
                } else {
                    if (a[j-1] != -1) {
                        a[j] = a[j-1];
                    }
                    a[j-1] = -1;
                }
            }
        }
        if (a[3] != -1) {
            ans += (a[3]-prev+1)*(s.length()-i);
            prev = a[3]+1;
            a[3] = -1;
        }
        // cout << "i: " << i << endl;
        // for (int j = 0; j < 4; j++) {
        //     cout << a[j] << " ";
        // }
        // cout << endl;
    }
    cout << ans << endl;
}