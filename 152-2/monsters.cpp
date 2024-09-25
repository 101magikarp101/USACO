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

int T, N, K;
int arr[300001];
map<int, set<int>> m;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        m.clear();
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            arr[i] %= K;
            if (arr[i] == 0) {
                arr[i] = K;
            }
            m[-arr[i]].insert(i+1);
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
                cout << *it2 << " ";
            }
        }
        cout << endl;
    }
}