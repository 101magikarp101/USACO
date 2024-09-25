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
int arr[300001];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    vector<int> v;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (v.size() == 0) {
            v.push_back(arr[i]);
        } else {
            int idx = lower_bound(v.begin(), v.end(), arr[i], greater<int>()) - v.begin();
            if (idx == v.size()) {
                v.push_back(arr[i]);
            } else {
                v[idx] = arr[i];
                v.erase(v.begin()+idx+1, v.end());
            }
        }
        cout << "v: ";
        for (int j = 0; j < v.size(); j++) {
            cout << v[j] << " ";
        }
        cout << endl;
    }
    cout << ans << endl;
}