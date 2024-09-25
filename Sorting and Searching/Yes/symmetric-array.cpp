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
        ll sum = 0;
        ll cur = 0;
        for (int i = 0; i < 2*N; i++) {
            cin >> d[i];
        }
        sort(d, d + 2*N);
        ll s = d[0]/2;
        if (d[0] % 2 == 1) {
            cout << "NO" << endl;
            goto cont;
        }
        for (int i = 0; i < N; i++) {
            if (d[2*i] != d[2*i+1]) {
                cout << "NO" << endl;
                goto cont;
            }
        }
        for (ll i = 1; i < N; i++) {
            ll temp = d[2*i] - d[2*(i-1)];
            // cout << "i: " << i << " temp: " << temp << endl;
            if (temp == 0) {
                cout << "NO" << endl;
                goto cont;
            }
            if (temp % (2*i) == 0) {
                cur += temp/(2*i);
                sum += cur;
            } else {
                cout << "NO" << endl;
                goto cont;
            }
        }
        if ((s-sum)%N == 0 && (s-sum)/N >= 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        cont:;
    }
    return 0;
}