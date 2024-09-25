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
#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

int C, N;
int maxs[100000];

int main() {
    auto start = chrono::high_resolution_clock::now();
    freopen("test.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> C >> N;
    bitset<18> b[100000];

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            b[i][j] = s[j] == 'G';
        }
    }
    string s = "";
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int res = (b[i] ^ b[j]).count();
            // if (res == 18) {
            //     cout << b[i] << " " << b[j] << endl;
            //     cout << "i: " << i << " j: " << j << endl;
            // }
            maxs[i] = max(maxs[i], res);
            maxs[j] = max(maxs[j], res);
        }
        s += to_string(maxs[i]) + "\n";
    }
    auto time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(time - start);
    cout << duration.count() << endl;
    cout << s;
    auto end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << duration.count() << endl;
    fclose(stdin);
    fclose(stdout);
}