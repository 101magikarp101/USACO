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
#define vi vector<int>
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define LLONG_MAX 9223372036854775807
#define LLONG_MIN -9223372036854775808
#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

ll N;

int main() {
    cin >> N;

    if (N%2==0 || (N%2==1&&N>=5)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}