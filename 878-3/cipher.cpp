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

using namespace std;

int T, N;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        string s;
        cin >> s;
        char cur = ' ';
        string ans;
        for (int j = 0; j < N; j++) {
            if (cur == ' ') {
                cur = s[j];
            } else if (s[j] == cur) {
                ans += s[j];
                cur = ' ';
            }
        }
        cout << ans << endl;
    }
}