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
#include <unordered_set>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int T, a, b;
string s;

int main() {
    cin >> T;
    while (T--) {
        cin >> s;
        bool flag = false;
        for (int i = 1; i < (s.length()+1)/2; i++) {
            if (s[i] != '0') {
                for (int j = 0; j < i; j++) {
                    cout << s[j];
                }
                cout << " ";
                for (int j = i; j < s.length(); j++) {
                    cout << s[j];
                }
                cout << endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            if (s.length() % 2 == 0) {
                a = stoi(s.substr(0, s.length()/2));
                b = stoi(s.substr(s.length()/2, s.length()/2));
                if (a < b) {
                    cout << a << " " << b << endl;
                } else {
                    cout << -1 << endl;
                }
            } else {
                cout << -1 << endl;
            }
        }
    }
}