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
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 1000000007

using namespace std;

int N, T, K;

int main() {
    cin >> N >> T;
    cin >> K;
    int low = 1;
    int high = N;
    int mid;
    while (low < high) {
        mid = (low+high)/2;
        cout << "? " << 1 << " " << mid << endl;
        cout.flush();
        int res;
        cin >> res;
        if (mid-res >= K) {
            high = mid;
        } else {
            low = mid+1;
        }
    }
    cout << "! " << low << endl;
}