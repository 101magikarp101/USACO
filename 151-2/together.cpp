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
        int xa, ya, xb, yb, xc, yc;
        cin >> xa >> ya >> xb >> yb >> xc >> yc;
        int dxb = xb - xa;
        int dyb = yb - ya;
        int dxc = xc - xa;
        int dyc = yc - ya;
        int ans = 1;
        if (!((dxb <= 0 && dxc >= 0) || (dxb >= 0 && dxc <= 0))) {
            ans += min(abs(dxb), abs(dxc));
        }
        if (!((dyb <= 0 && dyc >= 0) || (dyb >= 0 && dyc <= 0))) {
            ans += min(abs(dyb), abs(dyc));
        }
        cout << ans << endl;
    }
}