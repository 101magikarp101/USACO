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

int T;
int B, C, H;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> B >> C >> H;
        cout << min(C+H, B-1)*2+1 << endl;
    }
}