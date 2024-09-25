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
map<pair<int, int>, int> m;
int a[200001], b[200001];

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        int temp;
        for (int j = 0; j < N; j++) {
            cin >> temp;
            a[j] = temp;
        }
        for (int j = 0; j < N; j++) {
            cin >> temp;
            b[j] = temp;
        }
        for (int j = 0; j < N; j++) {
            m[make_pair(a[j], b[j])]++;
        }
        ll ans = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            for (int i = 1; i <= N/m.at(it->first); i++) {
                ans += i;
            }
        }
    }
}