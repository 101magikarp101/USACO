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
        int sum = 0;
        int cnt = 0;
        bool flag = false;
        for (int i = 0; i < N; i++) {
            if (s[i] == '.') {
                cnt++;
                sum++;
            } else {
                if (cnt >= 3) {
                    flag = true;
                    break;
                } else {
                    cnt = 0;
                }
            }
        }
        if (cnt >= 3) {
            flag = true;
        }
        if (flag) {
            cout << 2 << endl;
        } else {
            cout << sum << endl;
        }
    }
}