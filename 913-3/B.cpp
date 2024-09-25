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

int T;
string s;

int main() {
    cin >> T;
    while (T--) {
        cin >> s;
        vector<int> cap;
        vector<int> low;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'b') {
                if (low.size() > 0) {
                    low.erase(low.end()-1);
                }
            } else if (s[i] == 'B') {
                if (cap.size() > 0) {
                    cap.erase(cap.end()-1);
                }
            } else {
                if (s[i]-'a' >= 0 && s[i]-'a' <= 25) {
                    low.push_back(i);
                } else {
                    cap.push_back(i);
                }
            }
        }
        cap.insert(cap.end(), low.begin(), low.end());
        sort(cap.begin(), cap.end());
        for (int i = 0; i < cap.size(); i++) {
            cout << s[cap[i]];
        }
        cout << endl;
    }
}