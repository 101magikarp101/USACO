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

int arr[1001];

int main() {
    cin >> arr[1];
    for (int i = 2; i <= 1000; i++) {
        cout << "+ 1" << endl;
        cout.flush();
        cin >> arr[i];
        if (arr[i] == arr[1]) {
            cout << "! " << i-1 << endl;
            cout.flush();
            return 0;
        }
    }
    map<int, int> m;
    for (int i = 1; i <= 1000; i++) {
        m[arr[i]] = i;
    }
    int total = 1000;
    for (int i = 1; i <= 1000; i++) {
        cout << "+ 1000" << endl;
        cout.flush();
        int temp;
        cin >> temp;
        total += 1000;
        if (m[temp] != 0) {
            cout << "! " << total - m[temp] << endl;
            cout.flush();
            return 0;
        }
    }
}