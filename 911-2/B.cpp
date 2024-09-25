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
int a, b, c;

int main() {
    cin >> T;
    while (T--) {
        cin >> a >> b >> c;
        if ((b+c)%2==0) {
            cout << "1 "; 
        } else {
            cout << "0 ";
        }
        if ((a+c)%2==0) {
            cout << "1 "; 
        } else {
            cout << "0 ";
        }
        if ((a+b)%2==0) {
            cout << "1 "; 
        } else {
            cout << "0 ";
        }
        cout << endl;
    }
}