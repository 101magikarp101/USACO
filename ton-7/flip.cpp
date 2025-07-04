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

using namespace std;

int T, N;
string s;

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        cin >> s;
        int l = 0;
        int r = 0;
        int ans = 0;
        while (l < N-1 && r < N) {
            if (s[r] == 'A') {
                r++;
            } else {
                if (s[l] == 'A' && s[r] == 'B') {
                    ans += r-l;
                    s[r] = 'A';
                }
                l = r;
                r++;
                if (s[l] == 'B') {
                    l++;
                }
            }
            // cout << "l: " << l << " r: " << r << " ans: " << ans << endl;
        }
        cout << ans << endl;
    }
}