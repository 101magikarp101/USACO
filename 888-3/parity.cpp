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
int arr[200001];
int sorted[200001];

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            sorted[i] = arr[i];
        }
        sort(sorted, sorted+N);
        bool flag = false;
        for (int i = 0; i < N; i++) {
            if (arr[i] % 2 != sorted[i] % 2) {
                cout << "NO" << endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "YES" << endl;
        }
    }
}