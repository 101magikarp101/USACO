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

int N;

int main() {
    cin >> N;
    while (N--) {
        ll a, b;
        cin >> a >> b;
        ll a1[64], b1[64];
        memset(a1, 0, sizeof(a1));
        memset(b1, 0, sizeof(b1));
        a1[0] = a;
        b1[0] = b;
        for (int i = 1; i < 64; i++) {
            if (a == 1) {
                a1[i] = 1;
                break;
            }
            if (a % 2 == 0) {
                a /= 2;
            } else {
                a++;
            }
            a1[i] = a;
        }
        for (int i = 1; i < 64; i++) {
            if (b == 1) {
                b1[i] = 1;
                break;
            }
            if (b % 2 == 0) {
                b /= 2;
            } else {
                b--;
            }
            b1[i] = b;
        }
        ll ans = 2147483647;
        for (int i = 0; i < 64; i++) {
            if (a1[i] == 0) {
                break;
            }
            for (int j = 0; j < 64; j++) {
                if (b1[j] == 0 || a1[i] > b1[j]) {
                    break;
                }
                ans = min(ans, i+j+b1[j]-a1[i]);
            }
        }
        cout << ans << endl;
    }
}