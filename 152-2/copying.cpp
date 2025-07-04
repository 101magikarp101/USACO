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

int T, N, M;
vector<int> zero;
vector<int> one;
map<pair<int, int>, int> m;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        m.clear();
        zero.clear();
        one.clear();
        zero.push_back(-1);
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            bool temp = s[j] == '1';
            if (temp) {
                one.push_back(j);
            } else {
                zero.push_back(j);
            }
        }
        // cout << "zero: ";
        // for (int i = 0; i < zero.size(); i++) {
        //     cout << zero[i] << " ";
        // }
        // cout << endl;
        // cout << "one: ";
        // for (int i = 0; i < one.size(); i++) {
        //     cout << one[i] << " ";
        // }
        // cout << endl;
        for (int j = 0; j < M; j++) {
            int l, r;
            cin >> l >> r;
            auto rit = upper_bound(zero.begin(), zero.end(), r-1);
            rit--;
            int ri = *rit;
            if (ri == -1) {
                // cout << "ri: " << ri << endl;
                m[{-1, -1}]++;
                continue;
            }
            auto lit = lower_bound(one.begin(), one.end(), l-1);
            if (lit == one.end()) {
                m[{-1, -1}]++;
                continue;
            }
            int li = *lit;
            if (li >= ri) {
                // cout << "li: " << li << " ri: " << ri << endl;
                m[{-1, -1}]++;
                continue;
            }
            // cout << "li: " << li << " ri: " << ri << endl;
            m[{li, ri}]++;
        }
        cout << m.size() << endl;
    }
}