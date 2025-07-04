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
#include <chrono>

#define ll long long

using namespace std;

int T, N;

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        int s;
        cin >> s;
        int e;
        cin >> e;
        bool flag = false;
        for (int i = 1; i < N; i++) {
            int a, b;
            cin >> a >> b;
            if (a >= s && b >= e) {
                flag = true;
            }
        }
        if (flag) {
            cout << -1 << endl;
            continue;
        }
        cout << s << endl;
    }
    return 0;
}