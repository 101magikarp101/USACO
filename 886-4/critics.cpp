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

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        int arr[3];
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr + 3);
        if (arr[1] + arr[2] >= 10) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}