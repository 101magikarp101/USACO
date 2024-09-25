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
int arr[100005];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        if (arr[0] == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}