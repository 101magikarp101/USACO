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

int N;
ll a[200005];

int main() {
    cin >> N;
    bitset<18> res[200005];
    bitset<18> next[200005];
    ll count[18];
    vector<ll> flip;
    map<ll,ll> m;
    for (int i = 0; i < N-1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N-1; i++) {
        res[i] = bitset<18>(a[i]);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 17; j++) {
            if (i >> j & 1) {
                count[j]++;
            }
        }
    }
    next[0] = bitset<18>(0);
    for (int i = 0; i <= 17; i++) {
        int cnt = 0;
        for (int j = 1; j < N; j++) {
            if (res[j-1][i]) {
                next[j][i] = !next[j-1][i];
            } else {
                next[j][i] = next[j-1][i];
            }
            if (next[j][i]) {
                cnt++;
            }
        }
        if (cnt*2 == N) {
            flip.push_back(i);
        }
        if (cnt != count[i]) {
            for (int j = 0; j < N; j++) {
                next[j][i] = !next[j][i];
            }
        }
    }
    // cout << "res: " << endl;
    // for (int i = 0; i < N-1; i++) {
    //     cout << res[i] << endl;
    // }
    // cout << "next: " << endl;
    // for (int i = 0; i < N; i++) {
    //     cout << next[i] << endl;
    // }
    // cout << "flip: " << endl;
    // for (int i = 0; i < flip.size(); i++) {
    //     cout << flip[i] << endl;
    // }
    bool flag = true;
    for (int i = 0; i < N; i++) {
        m[next[i].to_ullong()]++;
        if (m[next[i].to_ullong()] == 2 || next[i].to_ullong() >= N) {
            flag = false;
            break;
        }
    }
    int id = 0;
    ll temp = 0;
    while (!flag) {
        flag = true;
        id++;
        temp = 0;
        for (int i = 0; i <= 17; i++) {
            if (id >> i & 1) {
                temp += 1 << flip[i];
            }
        }
        m.clear();
        for (int i = 0; i < N; i++) {
            m[next[i].to_ullong()^temp]++;
            if (m[next[i].to_ullong()^temp] == 2 || next[i].to_ullong()^temp >= N) {
                flag = false;
                break;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << (next[i].to_ullong()^temp) << " ";
    }
    cout << endl;
}