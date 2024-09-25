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

int T;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        string ans = "";
        for (int j = 1; j <= 8; j++) {
            for (int k = 1; k <= 8; k++) {
                char c;
                cin >> c;
                if (c != '.') {
                    ans += c;
                }
            }
        }
        cout << ans << endl;
    }
}