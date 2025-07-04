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

int T;
int X,Y,K;

int main() {
    cin >> T;
    while (T--) {
        cin >> X >> Y >> K;
        if (Y < X) {
            cout << X << endl;
        } else {
            if (K >= Y-X) {
                cout << Y << endl;
            } else {
                cout << Y + (Y-X-K) << endl;
            }
        }
    }
}