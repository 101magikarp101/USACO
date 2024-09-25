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
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

int T, N;
ll K;
int a[1005][1005];

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> K;
        memset(a, 0, sizeof(a));
        if (K%2 == 1) {
            cout << "No" << endl;
        } else if (N == 2) {
            if (K == 2) {
                cout << "Yes" << endl;
                cout << "1 0" << endl;
                cout << "1 0" << endl;
            } else if (K == 4) {
                cout << "Yes" << endl;
                cout << "1 1" << endl;
                cout << "1 1" << endl;
            } else if (K == 0) {
                cout << "Yes" << endl;
                cout << "0 0" << endl;
                cout << "0 0" << endl;
            } else {
                cout << "No" << endl;
            }
        } else if (K%4 == 0) {
            ll cnt = K/4;
            for (int i = 0; i < N; i+=2) {
                for (int j = 0; j < N; j+=2) {
                    if (cnt > 0) {
                        a[i][j] = 1;
                        a[i+1][j] = 1;
                        a[i][j+1] = 1;
                        a[i+1][j+1] = 1;
                        cnt--;
                    }
                }
            }
            cout << "Yes" << endl;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        } else {
            if (K < 6) {
                cout << "No" << endl;
            } else {
                a[0][0] = 1;
                a[0][1] = 1;
                a[1][0] = 1;
                a[2][1] = 1;
                a[1][2] = 1;
                a[2][2] = 1;
                ll cnt = (K-6)/4;
                for (int i = 0; i < N; i+=2) {
                    for (int j = 0; j < N; j+=2) {
                        if (cnt > 0 && a[i][j] == 0 && a[i+1][j] == 0 && a[i][j+1] == 0 && a[i+1][j+1] == 0) {
                            a[i][j] = 1;
                            a[i+1][j] = 1;
                            a[i][j+1] = 1;
                            a[i+1][j+1] = 1;
                            cnt--;
                        }
                    }
                }
                if (cnt == 1) {
                    a[2][0] = 1;
                    a[3][0] = 1;
                    a[2][3] = 1;
                    a[3][3] = 1;
                    cnt--;
                }
                if (cnt == 0) {
                    cout << "Yes" << endl;
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++){
                            cout << a[i][j] << " ";
                        }
                        cout << endl;
                    }
                } else {
                    cout << "No" << endl;
                }
            }
        }
    }
}