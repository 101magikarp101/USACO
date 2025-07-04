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
#define LLONG_MAX 9223372036854775807
#define MOD 1000000007

using namespace std;

int N, M;
vector<int> a[100001];

int main () {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(i);
        a[y+1].push_back(-i);
    }
    for (int i = 1; i <= N; i++) {
        if (i > 1) {

        }
    }
}