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

ll T, N;
ll d[200005];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < 2*N; i++) {
            cin >> d[i];
        }
        sort(d, d + 2*N);
        ll s = d[0]/2;
        ll sum = 0;
        ll cur = 0;
        bool flag = false;
        for (int i = 1; i < N; i++) {
            ll temp = d[2*i] - d[2*(i-1)];
            // cout << "i: " << i << " temp: " << temp << endl;
            if (temp == 0) {
                flag = true;
                break;
            }
            if (temp % (2*i) == 0) {
                cur += temp/(2*i);
                sum += cur;
            } else {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "NO" << endl;
            continue;
        } else {
            if ((s-sum)%N == 0 && (s-sum)/N >= 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }   
        memset(d, 0, sizeof(d));
    }
    return 0;
}