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

int T, X, K;

int main() {
    cin >> T;
    while (T--) {
        cin >> X >> K;
        while (true) {
            int sum = 0;
            int temp = X;
            for (int i = 0; i < 10; i++) {
                sum += temp % 10;
                temp /= 10;
            }
            if (sum % K == 0) {
                cout << X << endl;
                break;
            }
            X++;
        }
    }
}